/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_not_repite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 02:49:24 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/01 05:42:57 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int size_string(int argc, char **argv)
{
	int m;
	int i;
	int size;

	i = 0;
	m = 1;
	size = 0;
	while (m < argc)
	{
		while (argv[m][i])
		{
			i++;
			size++;
		}
		i = 0;
		m++;
	}
	return (size);
}
void fill_string(int argc, char **argv, char *string)
{
	int m;
	int i;
	int s;

	m = 1;
	i = 0;
	s = 0;
	while (m < argc)
	{
		while (argv[m][i])
		{
			string[s] = argv[m][i];
			i++;
			s++;
		}
		i = 0;
		m++;
		string[s++] = ' ';
	}
	string[s] = '\0';
}
int check_equal(char *c, char *string)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(string);
	while (i < size)
	{
		if(ft_atoi(c) == ft_atoi(&string[i]) && *c != ' ' && string[i] == ' ')
			return(1);
		i++;
	}
	return (0);
}
int check_not_repite(int argc,char **argv)
{
	int len_allocate;
	char *string;
	int v_return;
	int count;

	count = 0;
	v_return = 0;
	len_allocate = size_string(argc,argv);
	string = (char *)malloc(sizeof(char) * (len_allocate * 2 - 1));
	fill_string(argc,argv,string);
	while (string[count] != '\0')
	{
		if (check_equal(&string[count],&string[count + 1]) == 1 )
		{
			v_return = 1;
			break ;
		}
		count++;
	}
	free(string);
	string = NULL;
	return (v_return);
}