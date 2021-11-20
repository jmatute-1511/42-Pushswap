/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:34:34 by marvin            #+#    #+#             */
/*   Updated: 2021/11/14 13:34:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int bigger_number(t_list **stack)
{
    int big_n;
    t_list aux;

    big_n = 0;
    aux = (*stack);
    while (aux->next || aux->next == NULL)
    {
        if (big_n < aux->content)
            big_n = aux->content;
        if(aux->next == NULL)
            break
    }
    return (big_n);
}
int small_number(t_list **stack)
{
    int small_n;
    t_list aux;

    small_n = bigger_number(stack);
    aux = (*stack);
    while (aux->next || aux->next == NULL)
    {
        if (small_n > aux->content)
            small_n = aux->content;
        if(aux->next == NULL)
            break
    }
    return (small_n);
}