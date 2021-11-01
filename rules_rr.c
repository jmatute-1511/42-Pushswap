/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:59:59 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/01 18:05:54 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rule_ra(t_list *stack_a)
{
	t_list *head;
	t_list *ultimate;

	*head = *stack_a;
	*ultimate = *stack_a;
	while (ultimate->next)
		ultimate = ultimate->next;
	*stack_a = *head->next;
	ultimate->next = head;
	head->next = NULL;
}
void	rule_rb(t_list *stack_b)
{
	t_list *head;
	t_list *ultimate;

	*head = *stack_b;
	*ultimate = *stack_b;
	while (ultimate->next)
		ultimate = ultimate->next;
	*stack_b = *head->next;
	ultimate->next = head;
	head->next = NULL;
}

void	rule_rr(t_list *stack_a, t_list *stack_b)
{
	rule_ra(stack_a);
	rule_rb(stack_b);
}