/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:51:16 by marvin            #+#    #+#             */
/*   Updated: 2021/11/25 19:48:00 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int distance(int small_n, int big_n)
{
    int count;

    count = 0;
    while (small_n < big_n)
    {
        small_n++;
        count++;
    }
    count = count;
    return (count);
}

int bigger_number(t_list **stack)
{
    int big_n;
    t_list *aux;

    big_n = (*stack)->content;
    aux = (*stack);
    while (aux->next || aux->next == NULL)
    {
        if (big_n < aux->content)
            big_n = aux->content;
        if(aux->next == NULL)
            break;
        aux = aux->next;
    }
    return (big_n);
}
int small_number(t_list **stack)
{
    int small_n;
    t_list *aux;

    small_n = bigger_number(stack);
    aux = (*stack);
    while (aux->next || aux->next == NULL)
    {
        if (small_n > aux->content)
            small_n = aux->content;
        if(aux->next == NULL)
            break;
        aux = aux->next;
    }
    return (small_n);
}