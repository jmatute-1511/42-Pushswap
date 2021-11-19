/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:34:06 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/14 12:10:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_global global;
	int a;
	
	global.stack_a = NULL;
	global.stack_b = NULL;

	if (check_not_error(argc, argv) == 1)
	{
		ft_putstr_fd("ERROR ARGS", 2);
		exit (1);
	}
	global.stack_a = caption_stack(argc,argv, global.stack_a);
	global.end_a = end_stack(&global.stack_a);
	moves_when_size_five(&global.stack_a, &global.stack_b, &global.end_a);
	while(global.stack_a->next || global.stack_a->next == NULL)
	{
		printf(" %d",global.stack_a->content);
		if(global.stack_a->next == NULL)
			break;
		global.stack_a = global.stack_a->next;
	}
	return (0);
}