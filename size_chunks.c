/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:51:16 by marvin            #+#    #+#             */
/*   Updated: 2021/11/18 15:51:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int distance(int small_n, int big_n, char *option)
{
    int count;

    count = 0;
    while (small_n <= big_n)
    {
        small_n++;
        count++;
    }
    if(ft_strcmp(option, "100") == 0)
        count = count / 5;
    else if (ft_strcmp(option,"500") == 0)
        count = count / 11;
    return (count);
}