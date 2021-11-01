/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:00:42 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/01 17:55:23 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void rule_sa(t_list *stack_a)
{
	t_list *first;
	t_list *second;

	*first = *stack_a;
	*second = *stack_a->next;
	first->next = second->next;
	second->next = first;
	stack_a = second;
}
void rule_sb(t_list *stack_b)
{
	t_list *first;
	t_list *second;

	*first = *stack_b;
	*second = *stack_b->next;
	first->next = second->next;
	second->next = first;
	stack_b = second;
}
void	rule_ss(t_list *stack_a, t_list *stack_b)
{
	rule_sb(stack_b);
	rule_sa(stack_a);
}