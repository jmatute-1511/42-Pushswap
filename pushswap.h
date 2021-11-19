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
	t_list	*end_a;
	int		distace;
	int		small_n;
	int		big_n;
}			t_global;

int		check_is_not_empty(char *string);
void	*ft_calloc(size_t count, size_t size);
int		check_not_repite(int argc,char **argv);
int		check_not_error(int argc, char **argv);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_matrix(char **matrix);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		check_order(t_list **stack);
int 	bigger_number(t_list **stack);
int 	small_number(t_list **stack);
t_list *caption_stack(int argc, char **argv,t_list *stack);
t_list *end_stack(t_list **stack);
int		distance(int small_n, int big_n, char *option);
//RULES SS
void	rule_swap_stack(t_list **stack_a, char *option);
void	rule_swap_all(t_list **stack_a, t_list **stack_b);
// RULES RR
void	rule_rotate_stack(t_list **stack_a, char *option);
void	rule_rotate_all(t_list **stack_a, t_list **stack_b);
//RULES RRR
void	rule_reverse_stack(t_list **stack, char *option);
void	rule_reverse_all(t_list **stack_a, t_list **stack_b);
//RULE PUSH
void    rules_push_to(t_list **stack_a, t_list **stack_b, char *option);
// MOVES ACCORDING TO SIZE
void moves_when_size_five(t_list **stack_a,t_list **stack_b, t_list **end_a);
void move_size_three(t_list **stack_a, t_list **end_a);
#endif