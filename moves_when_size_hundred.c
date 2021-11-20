/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_when_size_hundred.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:42:36 by marvin            #+#    #+#             */
/*   Updated: 2021/11/18 12:42:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int holdn_moves(t_list **stack,t_global *global, int chunk, int flag)
{
    int     dist_chunk;
    int     count;
    t_list *aux;
    t_list *s_hold;

    count = 1;
    aux = (*stack);
    dist_chunk = distance(global->small_n, global->big_n) / 5;
    if (flag == 1)
    {
        while (aux->next)
        {
            if (aux->content < (small_n + dist_chunk) * chunk)
                s_hold = aux;
            aux = aux->next;
        }
        while (s_hold->next)
        {
            s_hold = s_hold->next;
            count++;
        }
    }
    else if (flag == 2)
    {
        while (aux->next)
        {
            if (aux->content < (small_n + dist_chunk) * chunk)
                break;
            count++;
            aux = aux->next;
        }
    }
    return (count);
}
void make_moves(t_list **stack_a, t_list *stack_b, char *option, int hold)
{
    if (ft_strcmp(option, "first") == 0)    
    {
        while (hold > 0)
        {
            rule_rotate_stack(stack_a, "stack_a");
            hold--;
        }
    }
    else if (ft_strcmp(option, "second"))
    {
        while (hold >= 0)
        {
            rule_reverse_stack(stack_a, "stack_a");
            hold--;
        }
        
    }
}
 int move_into_chunck(t_list **stack_a, t_list **stack_b, t_global *global,int chunk)
 {
    int first_hold;
    int second_hold;
    int size_chunk;
    
    first_hold = holdn_moves(stack_a,global,chunk,2)
    second_hold = holdn_moves(stack_a,global,chunk,1);
    global->big_n = bigger_number(stack_a);
    global->small_n = small_number(stack_a);
    global->distance = distance(global->small_n, global->big_n) / 5;
    size_chunk = global->small_n + global->distance;
    while (global->small_n < size_chunk)
    {
        if (first_hold < second_hold + 1)
            make_moves(stack_a,stack_b, "first", first_hold);
        else if(first_hold > second_hold + 1)
            make_moves(stack_a,stack_b, "second", first_hold);
    }
 }

void    moves_size_hundred(t_list **stack_a, t_list **stack_b, int size_stack, t_global *global)
{
    size_stack = ft_lstsize(stack_a);

    while ((*stack_a) != NULL)
    {

    }
}