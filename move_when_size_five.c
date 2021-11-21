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

t_list *end_stack(t_list **stack)
{
    t_list *end;

    end = (*stack);
    while( end->next)
        end = end->next;
    return (end);
}

void move_size_three(t_list **stack_a, t_list **end_a)
{
    int count;

    count = 0;
    while ( count < 2)
    {
        (*end_a) = end_stack(stack_a);
        if((*stack_a)->content > (*end_a)->content)
            rule_rotate_stack(stack_a,"rotate_a");
        else if ((*end_a)->content < (*stack_a)->content)
            rule_reverse_stack(stack_a,"reverse_a");
        else if((*stack_a)->content > (*stack_a)->next->content)
            rule_swap_stack(stack_a,"swap_a");
        else if ((*stack_a)->content < (*stack_a)->next->content)
            rule_swap_stack(stack_a,"swap_a");
        count++;
    }
}

int check_order(t_list **stack)
{
    t_list *aux;

    aux = (*stack);
    while (aux->next)
    {
        if (aux->content > aux->next->content)
            return (1);
        aux = aux->next;
    }
    return (0);
}

void moves_when_size_five(t_list **stack_a,t_list **stack_b, t_list **end_a)
{

    int size;
    int count;
    int aux;

    size = ft_lstsize(*stack_a);
    count = 0;
    if(size <= 5 && check_order(stack_a) == 1)
    {
        if ( size == 5)
        {
            rules_push_to(&(*stack_a), &(*stack_b), "push_to_b");
            rules_push_to(&(*stack_a),&(*stack_b), "push_to_b");
        }
        else if ( size == 4)
            rules_push_to(stack_a, stack_b, "push_to_b");
        if (check_order(stack_a) == 0)
            rule_swap_stack(stack_b, "swap_b");
        else
            move_size_three(stack_a, end_a);
        (*end_a) = end_stack(stack_a);
        aux = (*stack_a)->next->content;
        while (count <= 3)
        {
             if ((*stack_b) != NULL)
                    rules_push_to(stack_a, stack_b, "push_to_a");
            (*end_a) = end_stack(stack_a);
            if ((*stack_a)->content < (*end_a)->content && (*stack_a)->content > aux)
            {
                aux = (*stack_a)->content;
                rule_reverse_stack(stack_a, "reverse_a");
                rule_swap_stack(stack_a,"swap_a");
                rule_rotate_stack(stack_a, "rotate_a");
                rule_rotate_stack(stack_a, "rotate_a");
            }
           else if((*end_a)->content < (*stack_a)->content)
                rule_rotate_stack(stack_a, "rotate_a");
            else if ((*stack_a)->content > (*stack_a)->next->content)
                rule_swap_stack(stack_a, "swap_a");
            count++;
        }
    }
}