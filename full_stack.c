/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:31:33 by jmatute-          #+#    #+#             */
/*   Updated: 2021/10/31 17:49:49 by jmatute-         ###   ########.fr       */
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
		write(1,"ERROR 1\n",8);
		return (1);
	}
	while (m < argc)
	{
		while (ft_isdigit(argv[m][i]) != 0 || argv[m][i] == ' ' || argv[m][i] == '-')
		{
			if (argv[m][i] == '-' && argv[m][i - 1] != ' ')
			{
				write(1,"ERROR 2\n",8);
				return (1);
			}
			i++;
		}
		if (ft_isdigit(argv[m][i]) == 0 && argv[m][i] != '\0')
		{
			printf("LUGAR DONDE ROMPE %c \n",argv[m][i]);
			write(2,"ERROR 3\n",8);
			return (1);
		}
		m++;
	}
	return (0);
}

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
	char **first;
	int aux;
	t_list *stack;

	count = 1;
	first = ft_split(argv[1], ' ');
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

	m = 2;
	stack = create_first_list(argv);
	while (m < argc)
	{
		matrix = ft_split(argv[m],' ');
		save_list(matrix,stack);
		m++;
	}
	free_matrix(matrix);
	return (stack);
}

int main(int argc, char **argv)
{
	t_list *stack;
	int a;

	a = check_not_error(argc,argv);
	printf("VALOR DE A : %d\n",a);
	if (a == 1)
	{
		ft_putstr_fd("ERROR ARGS", 2);
		exit (1);
	}
	stack = caption_stack(argc, argv, stack);
	while (stack->next)
	{
		printf("%d ",stack->content);
		stack = stack->next;
	}
	printf("%d ",stack->content);
	return (0);
}