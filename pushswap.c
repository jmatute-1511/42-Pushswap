/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:34:06 by jmatute-          #+#    #+#             */
/*   Updated: 2021/12/11 18:42:18 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_global	global;

	global.stack_a = NULL;
	global.stack_b = NULL;
	if (check_not_error(argc, argv) > 0 || check_range(argc, argv) == 1)
	{
		if (check_not_error(argc, argv) == 1 || check_range(argc, argv) == 1)
			ft_putstr_fd("ERROR ARGS\n", 1);
		exit (1);
	}
	global.stack_a = caption_stack(argc, argv, global.stack_a);
	if (check_order(&global.stack_a) == 0 || not_repite(&global.stack_a) == 1)
	{
		if (not_repite(&global.stack_a) == 1)
			ft_putstr_fd("ERROR ARGS\n", 1);
		exit (1);
	}
	if (ft_lstsize(global.stack_a) <= 5)
		moves_when_size_five(&global.stack_a, &global.stack_b);
	else if (ft_lstsize(global.stack_a) <= 100)
		moves_depending_on_size(&global.stack_a, &global.stack_b, &global, 7);
	else if (ft_lstsize(global.stack_a) > 100)
		moves_depending_on_size(&global.stack_a, &global.stack_b, &global, 11);
	free_lst(&global.stack_a);
	return (0);
}
