/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:37:01 by marvin            #+#    #+#             */
/*   Updated: 2021/11/05 17:37:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(t_list **stack_a, t_list **stack_b, t_list *head)
{
	if ((*stack_a) == NULL)
	{
		(*stack_a) = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		(*stack_a)->next = NULL;
	}
	else
	{
		(*stack_b) = (*stack_b)->next;
		head->next = (*stack_a);
		(*stack_a) = head;
	}
}

void	push_b(t_list **stack_a, t_list **stack_b, t_list *head)
{
	if ((*stack_b) == NULL)
	{
		(*stack_b) = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		(*stack_b)->next = NULL;
	}
	else
	{
		(*stack_a) = (*stack_a)->next;
		head->next = (*stack_b);
		(*stack_b) = head;
	}
}

void	rules_push_to(t_list **stack_a, t_list **stack_b, char *option)
{
	t_list	*head;

	if (ft_strcmp(option, "push_to_a") == 0 && (*stack_b) != NULL)
	{
		head = (*stack_b);
		push_a(stack_a, stack_b, head);
		write(1, "pa\n", 3);
	}
	else if (ft_strcmp(option, "push_to_b") == 0 && (*stack_a) != NULL)
	{
		head = (*stack_a);
		push_b(stack_a, stack_b, head);
		write(1, "pb\n", 3);
	}
}
