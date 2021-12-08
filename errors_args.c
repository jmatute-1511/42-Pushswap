/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:36:41 by jmatute-          #+#    #+#             */
/*   Updated: 2021/10/30 15:36:41 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int not_repite(t_list **stack)
{
	t_list *aux_next;
	t_list *aux;

	aux_next = (*stack)->next;
	aux =(*stack);

	while (aux)
	{
		while (aux_next)
		{
			if (aux->content == aux_next->content)
				return (1);
			aux_next = aux_next->next;
		}
		aux = aux->next;
		if(aux_next != NULL)
			aux_next = aux_next;
	}
	return  (0);
}

int	check_is_not_empty(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (ft_isdigit(string[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_not_error(int argc, char **argv)
{
	int i;
	int m;

	i = 0;
	m = 1;
	while (m < argc)
	{
		if (check_is_not_empty(argv[m]) == 0)
			return (1);
		while (ft_isdigit(argv[m][i]) != 0 || argv[m][i] == ' ' || argv[m][i] == '-')
		{
			if (argv[m][i] == '-' && argv[m][i - 1] != ' ' && i != 0)
				return (1);
			i++;
		}
		if (ft_isdigit(argv[m][i]) == 0 && argv[m][i] != '\0')
			return (1);
		i = 0;
		m++;
	}
	return (0);
}

int check_range(int argc, char **argv)
{
	char **matrix;
	long number;
	int i;
	int m;

	i = 1;
	while (argv[i])
	{
		matrix = ft_split(argv[i], ' ');
		m = 0;
		while (matrix[m])
		{
			number = ft_long_atoi(matrix[m]);
			if(number > 2147483647 || number < -2147483648)
			{
				free_matrix(matrix);
				return (1);
			}
			m++;
		}
		free_matrix(matrix);
		i++;
	}
	return (0);
}