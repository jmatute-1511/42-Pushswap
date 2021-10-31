/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:29:47 by jmatute-          #+#    #+#             */
/*   Updated: 2021/10/30 21:29:47 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

int	check_is_not_empty(char *string);
int		check_not_error(int argc, char **argv);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_matrix(char **matrix);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
#endif