/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:24:34 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/25 13:49:18 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char   *s;

    s = (unsigned char*)b;
    while (len > 0)
    {
        *s = (unsigned char)c;
        s++;
        len--;
    }
    return (b);
}
