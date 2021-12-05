/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:34:06 by jmatute-          #+#    #+#             */
/*   Updated: 2021/12/05 15:56:51 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void print(t_list **stack_n)
{
	t_list *stack;

	stack = (*stack_n);
	while (stack)
	{
		printf("%d ",stack->content);
		stack = stack->next;
	}
}
int main(int argc, char **argv)
{
	t_global global;
	int size;
	int hold_s;
	global.stack_a = NULL;
	global.stack_b = NULL;

	if (check_not_error(argc, argv) == 1)
	{
		ft_putstr_fd("ERROR ARGS\n", 1);
		exit (1);
	}
	global.stack_a = caption_stack(argc,argv, global.stack_a);
	if (check_order(&global.stack_a) == 0)
		exit(1);
	if (not_repite(&global.stack_a) == 1)
	{
		ft_putstr_fd("ERROR ARGS\n", 1);
		exit(1);
	}
	if (size <= 5)
		moves_when_size_five(&global.stack_a, &global.stack_b, &global.end_a);
	else if (size <= 100)
		moves_depending_on_size(&global.stack_a,&global.stack_b,&global,7);
	else if (size > 100)
		moves_depending_on_size(&global.stack_a,&global.stack_b,&global, 11);*/
	print(&global.stack_a);
	return (0);
}