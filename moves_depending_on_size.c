/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_depending_on_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:42:36 by marvin            #+#    #+#             */
/*   Updated: 2021/11/26 16:05:36 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	moves_to_dump(t_list **stack, int big_n)
{
	int count;
	t_list *aux;

	aux =(*stack);
	count = 0;
	if (aux->content == big_n /*|| aux->content == big_n - 1*/)
			return(0);
	while (aux)
	{
		if(aux->content == big_n /*|| aux->content == big_n - 1*/)
			break;
		count++;
		aux = aux->next;
	}
	return (count);
}
void dump_on_stack(t_list **stack_a, t_list **stack_b)
{
	int big_n;
	int moves;
	int size;

	while ((*stack_b)->next)
	{
		size = ft_lstsize((*stack_b));
		big_n = bigger_number (stack_b);
		moves = moves_to_dump(stack_b, big_n);
		if (moves == 1)
			rule_swap_stack(stack_b,"swap_b");
		else if ( moves < size / 2)
			rule_nrotate(stack_b,"rotate_b",moves);
		else
		{
			moves = size - moves;
			rule_nreverse(stack_b, "reverse_b", moves);
		}
	//	if (ft_lstsize(*stack_a) )
		rules_push_to(stack_a, stack_b,"push_to_a");
	}
	rules_push_to(stack_a, stack_b,"push_to_a");
}
void make_moves(t_list **stack_a, char *option, int hold)
{
	if (ft_strcmp(option, "first") == 0)
		rule_nrotate(stack_a, "rotate_a", hold);
	else if (ft_strcmp(option, "second") == 0)
		rule_nreverse(stack_a, "reverse_a", hold);
}
void move_chunck(t_list **stack_a, t_global *global, int topchunk)
{
	int first_hold;
	int second_hold;

	first_hold = hold_first(stack_a,global,topchunk);
	second_hold = hold_second(stack_a,topchunk);
	if (first_hold < second_hold)
		make_moves(stack_a, "first", first_hold);
	else if(first_hold > second_hold)
		make_moves(stack_a, "second", second_hold);
	else if (second_hold == 0 && first_hold != 0)
		rule_reverse_stack(stack_a, "reverse_a");
	else if (first_hold == second_hold)
		rule_nrotate(stack_a, "rotate_a", first_hold);
}
void part_chunk(t_list **stack_b, int top_chunk)
{
	if((*stack_b)->next->content)
	{
		if((*stack_b)->content > top_chunk/2)
			rule_rotate_stack(stack_b,"rotate_b");
	}
}
void    moves_depending_on_size(t_list **stack_a, t_list **stack_b, t_global *global, int n_chunks)
{
    int chunk;
	int final_chunk;
	int top_chunk;
	int moves;

    chunk = 1;
	moves = 0;
	global->small_n = small_number(stack_a);
	global->big_n = bigger_number(stack_a);
	global->distance = distance(global->small_n, global->big_n);
	final_chunk = (global->distance / n_chunks) + global->small_n;
	top_chunk = final_chunk;
    while ((*stack_a) != NULL)
	{
		if (chunk == n_chunks / 3)
			top_chunk = (final_chunk * chunk) + (global->distance % n_chunks);
		else
			top_chunk = final_chunk * chunk;
		while (moves < top_chunk && (*stack_a)->next)
		{
			if (ft_lstsize((*stack_b)) < top_chunk)
			{
				move_chunck(stack_a, global,top_chunk);
				rules_push_to(stack_a,stack_b,"push_to_b");
			}
			if (ft_lstsize(*stack_b) > 1)
			{
				if ((*stack_b)->content  < (*stack_b)->next->content)
					rule_swap_stack(stack_b,"swap_b");
			}
			moves++;
		}
		if((*stack_a)->next == NULL)
			rules_push_to(stack_a,stack_b,"push_to_b");
		chunk++;
	}
	dump_on_stack(stack_a, stack_b);
}