/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/26 16:58:46 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		chomp_at_dash(t_room *r, int i)
{
 	char    *space;

    space = ft_strchr(r->connection[i], '-');
    *space = '\0';	
	return (0);
}


int		add_con_to_map(t_room *r)
{
	int i;
	int j;
	int k;
	int l;
	int flag;

	i = 0;
	k = 0;
	j = 0;
	l = 0;
	flag = 0;
	while (r->connection[i])
	{
		chomp_at_dash(r, i);
		while (ft_strcmp(r->connection[i], r->rooms[j]) != 0)
		{
			j++;
			if (r->rooms[j] == 0)
			{
				ft_putstr_fd("Major error, no room name exists for a connection", 2);
				return (-1);
			}
		}
		while (r->connection[i][k])
			k++;
		while (ft_strcmp(&r->connection[i][k + 1], r->rooms[l]) != 0)
		{
			l++;
			if (r->rooms[l] == 0)
			{
				ft_putstr_fd("Major error, no room name exists for a connection", 2);
				return (-1);
			}
		}
		r->map[j][l] = '1';
		r->map[l][j] = '1';
		i++;
		j = 0;
		k = 0;
		l = 0;
	}	
	return (0);
}


