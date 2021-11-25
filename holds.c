/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:52:00 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/25 15:24:49 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int hold_second(t_list **stack, int top_chunk)
{
	int count;
	int flag;
	t_list *aux;


	count = 1;
	aux = (*stack);
	while (aux)
	{
		if (aux->content <= top_chunk)
			count = 1;
		else
			count++;
		aux = aux->next;
	}
	return (count);
}

int hold_first(t_list **stack,t_global *global, int top_chunk)
{
	t_list	*aux;
	int		count;

	count = 0;
	aux = (*stack);
	if (aux->content <= top_chunk)
			return(0);
	while (aux)
	{
		if (aux->content <= top_chunk)
			break;
		count++;
		aux = aux->next;
	}
	return (count);
}
