/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:47 by jmatute-          #+#    #+#             */
/*   Updated: 2021/12/11 13:44:47 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	not_repite(t_list **stack)
{
	t_list	*aux_next;
	t_list	*aux;

	aux_next = (*stack)->next;
	aux = (*stack);
	while (aux->next)
	{
		while (aux_next)
		{
			if (aux->content == aux_next->content)
				return (1);
			aux_next = aux_next->next;
		}
		aux = aux->next;
		aux_next = aux->next;
	}
	return (0);
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

int	aux_check_error(char **argv, int *i)
{
	while (ft_isdigit(argv[i[0]][i[1]]) != 0 || argv[i[0]][i[1]] == ' ' || \
	argv[i[0]][i[1]] == '-' || argv[i[0]][i[1]] == '+')
	{
		if ((argv[i[0]][i[1]] == '-' || argv[i[0]][i[1]] == '+') && \
		argv[i[0]][i[1] - 1] != ' ' && i[1] != 0)
			return (1);
		if ((argv[i[0]][i[1]] == '-' || argv[i[0]][i[1]] == '+') && \
		ft_isdigit(argv[i[0]][i[1] + 1]) == 0 && i[1] != 0)
			return (1);
		i[1]++;
	}
	return (0);
}

int	check_not_error(int argc, char **argv)
{
	int	i[2];

	i[1] = 0;
	i[0] = 1;
	if (argc == 1)
		return (2);
	while (i[0] < argc)
	{
		if (check_is_not_empty(argv[i[0]]) == 0)
			return (1);
		if (aux_check_error(argv, i) == 1)
			return (1);
		if (ft_isdigit(argv[i[0]][i[1]]) == 0 && argv[i[0]][i[1]] != '\0')
			return (1);
		i[1] = 0;
		i[0]++;
	}
	return (0);
}

int	check_range(int argc, char **argv)
{
	char	**matrix;
	long	number;
	int		i;
	int		m;

	i = 1;
	while (argv[i])
	{
		matrix = ft_split(argv[i], ' ');
		m = 0;
		while (matrix[m])
		{
			number = ft_long_atoi(matrix[m]);
			if (number > 2147483647 || number < -2147483648)
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
