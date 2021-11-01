/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:08:17 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/01 18:31:48 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rule_rra(t_list *stack_a)
{
	t_list *penultimate;
	t_list *head;

	head = stack_a;
	*penultimate = *stack_a;
	while (penultimate->next->next)
			penultimate = penultimate->next;
	penultimate->next = NULL;
}