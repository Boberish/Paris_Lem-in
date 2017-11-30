/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 12:12:38 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_ants(t_room *r)
{
	int i;
	int j;
	int k;

	k = ft_int_array_len(r->bpath) - 1;
	i = 1;
	j = 1;
	while (1)
	{
		i = 1;
		while (i < j)
		{
			if (line_print(i, j - i, r, k) == 1)
				return ;
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

int		line_print(int i, int j, t_room *r, int k)
{
	if ((j > k || i >= r->ants + 1))
	{
		if (j > k && i >= r->ants)
			return (1);
		return (0);
	}
	ft_putchar('L');
	ft_putnbr(i);
	ft_putchar('-');
	ft_putstr(r->rooms[r->bpath[j]]);
	ft_putchar(' ');
	return (2);
}
