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
	int		distance;
	int		small_n;
	int		big_n;
	int		top_chunks;
}			t_global;
// LIBFT FUCTIONS
void	*ft_calloc(size_t count, size_t size);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_matrix(char **matrix);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
// CALCULATE MOVES
int		hold_first(t_list **stack, t_global *global, int topchunk);
int		hold_second(t_list **stack, int top_chunk);
int		bigger_number(t_list **stack);
int		small_number(t_list **stack);
int		distance(int small_n, int big_n);
// STACK
t_list	*caption_stack(int argc, char **argv, t_list *stack);
t_list	*end_stack(t_list **stack);
void	make_moves(t_list **stack_a, char *option, int hold);
void	move_chunck(t_list **stack_a, t_global *global, int top_chunk);
int		moves_to_dump(t_list **stack, int big_n);
void	dump_on_stack(t_list **stack_a, t_list **stack_b);
void	free_lst(t_list **stack);
//ERROR FUCTIONS
int		check_is_not_empty(char *string);
int		check_order(t_list **stack);
int		check_not_error(int argc, char **argv);
int		check_not_repite(int argc, char **argv);
int		not_repite(t_list **stack);
int		check_range(int argc, char **argv);
//RULES SS
void	rule_swap_stack(t_list **stack_a, char *option);
void	rule_swap_all(t_list **stack_a, t_list **stack_b);
// RULES RR
void	rule_rotate_stack(t_list **stack_a, char *option);
void	rule_rotate_all(t_list **stack_a, t_list **stack_b);
void	rule_nrotate(t_list **stack, char *option, int iterator);
//RULES RRR
void	rule_reverse_stack(t_list **stack, char *option);
void	rule_reverse_all(t_list **stack_a, t_list **stack_b);
void	rule_nreverse(t_list **stack, char *option, int iterator);
//RULE PUSH
void	push_b(t_list **stack_a, t_list **stack_b, t_list *head);
void	push_a(t_list **stack_a, t_list **stack_b, t_list *head);
void	rules_push_to(t_list **stack_a, t_list **stack_b, char *option);
// MOVES ACCORDING TO SIZE
void	moves_when_size_five(t_list **stack_a, t_list **stack_b);
void	move_size_three(t_list **stack_a, t_list **end_a);
void	moves_depending_on_size(t_list **stack_a, t_list **stack_b, \
t_global *global, int size);
#endif