/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:52:00 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/21 16:15:15 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int hold_second(t_list **stack, int top_chunk, int first_hold)
{
	int		count;
	int		cunt2;
	t_list	*aux;
	t_list	*s_hold;

    count = 0;
	cunt2 = 0;
    aux = (*stack);
	while (aux->next || aux->next == NULL)
	{
		if (aux && aux->content  < top_chunk)
			s_hold = aux;
		if (aux->next == NULL || aux == NULL)
			break;
		aux = aux->next;
		cunt2++;
	}
	while (s_hold)
	{
		count++;
		if (s_hold->next == NULL)
		{
			break;
		}
		s_hold = s_hold->next;
	}
	return (count);
}

int hold_first(t_list **stack,t_global *global, int top_chunk)
{
	t_list	*aux;
	int		count;

	count = 0;
	aux = (*stack);
	if(aux)
	{
		while (aux->next)
		{
			if (aux->content <= top_chunk)
				break;
			count++;
			aux = aux->next;
		}
	}
	return (count);
}
