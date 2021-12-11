/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_when_size_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:45:33 by marvin            #+#    #+#             */
/*   Updated: 2021/11/11 12:45:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*end_stack(t_list **stack)
{
	t_list	*end;

	end = (*stack);
	while (end->next)
		end = end->next;
	return (end);
}

void	move_size_three(t_list **stack_a, t_list **end_a)
{
	int	count;
	int	big_n;

	big_n = bigger_number(stack_a);
	count = 0;
	while (count < 2)
	{
		(*end_a) = end_stack(stack_a);
		if ((*stack_a)->content == big_n)
			rule_rotate_stack(stack_a, "rotate_a");
		else if ((*end_a)->content < (*stack_a)->content)
			rule_reverse_stack(stack_a, "reverse_a");
		else if ((*stack_a)->content > (*end_a)->content)
			rule_rotate_stack(stack_a, "rotate_a");
		else if ((*stack_a)->content > (*stack_a)->next->content)
			rule_swap_stack(stack_a, "swap_a");
		else if ((*stack_a)->next->content == big_n)
			rule_reverse_stack(stack_a, "reverse_a");
		count++;
	}
}

int	check_order(t_list **stack)
{
	t_list	*aux;

	aux = (*stack);
	while (aux)
	{
		if (aux->next)
		{
			if (aux->content > aux->next->content)
				return (1);
		}
		aux = aux->next;
	}
	return (0);
}

void	push_smalls(t_list **stack_a, t_list **stack_b, t_list **end_a)
{
	int	aux;
	int	small;

	aux = 0;
	while (aux < 2 && ft_lstsize(*stack_a) > 3)
	{
		small = small_number(stack_a);
		if ((*stack_a)->content == small)
		{
			rules_push_to(stack_a, stack_b, "push_to_b");
			aux++;
		}
		else if ((*stack_a)->next->content == small)
			rule_rotate_stack(stack_a, "rotate_a");
		else if ((*end_a)->content == small)
			rule_reverse_stack(stack_a, "reverse_a");
		else
			rule_rotate_stack(stack_a, "rotate_a");
	}
}

void	moves_when_size_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*end_a;

	end_a = end_stack(stack_a);
	push_smalls(stack_a, stack_b, &end_a);
	move_size_three(stack_a, &end_a);
	while ((*stack_b) != NULL)
		rules_push_to(stack_a, stack_b, "push_to_a");
}
