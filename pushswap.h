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

typedef struct s_global
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*head_a;
	t_list	*head_b;
}			t_global;
int		check_is_not_empty(char *string);
void	*ft_calloc(size_t count, size_t size);
int		check_not_repite(int argc,char **argv);
int		check_not_error(int argc, char **argv);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_matrix(char **matrix);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
t_list *caption_stack(int argc, char **argv,t_list *stack);

//RULES SS
void rule_sa(t_list *stack_a);
void rule_sb(t_list *stack_b);
void	rule_ss(t_list *stack_a, t_list *stack_b);
//RULES RR
void	rule_ra(t_list *stack_a);
void	rule_rb(t_list *stack_b);
void	rule_rr(t_list *stack_a, t_list *stack_b);
//RULES RRR
void	rule_rra(t_list *stack_a);
#endif