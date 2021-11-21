/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:59:59 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/21 15:29:33 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rule_rotate_stack(t_list **stack,char *option)
{
	t_list *head;
	t_list *ultimate;

	head = (*stack);
	ultimate = (*stack);
	while (ultimate->next)
		ultimate = ultimate->next;
	(*stack) = head->next;
	ultimate->next = head;
	head->next = NULL;
	if (ft_strcmp(option, "rotate_a") == 0)
		write(1, "ra\n", 4);
	else if(ft_strcmp(option, "rotate_b") == 0)
		write(1, "rb\n", 4);
}
void	rule_rotate_all(t_list **stack_a, t_list **stack_b)
{
	rule_rotate_stack(stack_a, "NON");
	rule_rotate_stack(stack_b, "NON");
	write(1,"rr\n",4);
}
void rule_nrotate(t_list **stack, char *option, int iterator)
{
	while (iterator > 0)
	{
		rule_rotate_stack(stack,option);
		iterator--;
	}
}