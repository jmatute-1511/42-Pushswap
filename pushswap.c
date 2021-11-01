/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:34:06 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/01 18:19:56 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_global global;

	int a;

	if (check_not_error(argc, argv) == 1)
	{
		ft_putstr_fd("ERROR ARGS", 2);
		exit (1);
	}
	global.stack_a = caption_stack(argc, argv, global.stack_a);
	rule_rra(global.stack_a);
	while (global.stack_a->next)
	{
		printf("%d ",global.stack_a->content);
		global.stack_a = global.stack_a->next;
	}
	printf("%d ",global.stack_a->content);
	return (0);
}