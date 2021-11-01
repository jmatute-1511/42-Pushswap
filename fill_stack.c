/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:31:33 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/01 06:34:19 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void save_list(char **matrix, t_list *stack)
{
	int m;
	int aux;

	m = 0;
	while (matrix[m])
	{
		aux = ft_atoi(matrix[m]);
		ft_lstadd_back(&stack,ft_lstnew(aux));
		m++;
	}
}
t_list *create_first_list(char **argv)
{
	int count;
	int m;
	char **first;
	int aux;
	t_list *stack;

	count = 1;
	m = 1;
	while (check_is_not_empty(argv[m]) == 0 )
		m++;
	first = ft_split(argv[m], ' ');
	aux = ft_atoi(first[0]);
	stack = ft_lstnew(aux);
	while (first[count])
	{
		aux = ft_atoi(first[count]);
		ft_lstadd_back(&stack,ft_lstnew(aux));
		count++;
	}
	free_matrix(first);
	return (stack);
}
t_list *caption_stack(int argc, char **argv,t_list *stack)
{
	int m;
	char **matrix;

	m = 1;
	stack = create_first_list(argv);
	while (check_is_not_empty(argv[m]) == 0)
		m++;
	while (m  + 1 < argc)
	{
		matrix = ft_split(argv[m + 1],' ');
		save_list(matrix,stack);
		m++;
	}
	if (argc > 2)
		free_matrix(matrix);
	return (stack);
}