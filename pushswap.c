/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:34:06 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/26 15:54:17 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_global global;
	int size;
	int hold_s;
	global.stack_a = NULL;
	global.stack_b = NULL;

	if (check_not_error(argc, argv) == 1)
	{
		ft_putstr_fd("ERROR ARGS", 2);
		exit (1);
	}
	global.stack_a = caption_stack(argc,argv, global.stack_a);
	size = ft_lstsize(global.stack_a);
	global.end_a = end_stack(&global.stack_a);
	global.small_n = small_number(&global.stack_a);
	global.big_n = bigger_number(&global.stack_a);
	//printf("\n %d %d\n", global.small_n, global.big_n);
	if (size <= 5)
		moves_when_size_five(&global.stack_a, &global.stack_b, &global.end_a);
	else if (size <= 100)
		moves_depending_on_size(&global.stack_a,&global.stack_b,&global,7);
	else if (size <= 500)
		moves_depending_on_size(&global.stack_a,&global.stack_b,&global, 11);
	//printf ("\n SIZEEE %d\n", ft_lstsize(global.stack_b));
	/*while(global.stack_b->next || global.stack_b->next == NULL)
	{
		printf(" %d",global.stack_b->content);
		if(global.stack_b->next == NULL)
			break;
		global.stack_b = global.stack_b->next;
	}
	printf("\n\n\n");*/
	//printf(" \n SIZEEE B %d\n", ft_lstsize(global.stack_b));
	while(global.stack_a->next || global.stack_a->next == NULL)
	{
		printf(" %d",global.stack_a->content);
		if(global.stack_a->next == NULL)
			break;
		global.stack_a = global.stack_a->next;
	}
	//printf("\n%p ",global.end_a->next);
	return (0);
}