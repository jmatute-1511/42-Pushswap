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

int	check_is_not_empty(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (ft_isdigit(string[i] != 0))
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
	if (argc == 2 && check_is_not_empty(argv[m]) == 0)
	{
		write(2,"ERROR 1",8);
		return (1);
	}
	while (m < argc)
	{
		while (ft_isdigit(argv[m][i]) != 0 || argv[m][i] == ' ' || argv[m][i] == '-')
		{
			if ( argv[m][i] == '-' && argv[m][i - 1] != ' ')
			{
				write(2,"ERROR 2",8);
				return (1);
			}
			i++;
		}
		if (ft_isdigit(argv[m][i] == 0))
		{
			write(2,"ERROR 3",8);
			return (1);
		}
		m++;
	}
	return (0);
}

