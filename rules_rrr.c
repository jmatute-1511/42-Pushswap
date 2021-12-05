/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:08:17 by jmatute-          #+#    #+#             */
/*   Updated: 2021/12/03 16:10:08 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rule_reverse_stack(t_list **stack, char *option)
{
	t_list *penultimate;
	t_list *ultimate;

	penultimate = (*stack);
	while (penultimate->next->next)
			penultimate = penultimate->next;
	ultimate = penultimate->next;
	ultimate->next = (*stack);
	penultimate->next = NULL;
	(*stack) = ultimate;
	if (ft_strcmp(option,"reverse_a") == 0)
		write(1, "rra\n", 4);
	else if (ft_strcmp(option, "reverse_b") == 0)
		write(1, "rrb\n", 4);
}

void rule_reverse_all(t_list **stack_a, t_list **stack_b)
{
	rule_reverse_stack(stack_a, "NON");
	rule_reverse_stack(stack_b, "NON");
	write(1,"rrr\n", 4);
}
void rule_nreverse(t_list **stack, char *option, int iterator)
{
	while (iterator > 0)
	{
		rule_reverse_stack(stack,option);
		iterator--;
	}

}