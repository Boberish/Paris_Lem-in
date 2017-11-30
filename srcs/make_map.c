/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 11:47:43 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		chomp_at_dash(t_room *r, int i)
{
	char	*space;

	space = ft_strchr(r->connection[i], '-');
	*space = '\0';
	return (0);
}

int		add_con1(t_room *r, int *i)
{
	chomp_at_dash(r, i[0]);
	while (ft_strcmp(r->connection[i[0]], r->rooms[i[1]]) != 0)
	{
		(i[1])++;
		if (r->rooms[i[1]] == 0)
		{
			ft_putstr_fd("error, no room name exists for connection\n", 2);
			return (-1);
		}
	}
	while (r->connection[i[0]][i[2]])
		(i[2])++;
	while (ft_strcmp(&r->connection[i[0]][i[2] + 1], r->rooms[i[3]]) != 0)
	{
		(i[3])++;
		if (r->rooms[i[3]] == 0)
		{
			ft_putstr_fd("error, no room name exists for connection\n", 2);
			return (-1);
		}
	}
	return (0);
}

int		add_con_to_map(t_room *r)
{
	int i[4];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	while (r->connection[i[0]])
	{
		if (add_con1(r, i) == -1)
			return (-1);
		r->map[i[1]][i[3]] = '1';
		r->map[i[3]][i[1]] = '1';
		(i[0])++;
		i[1] = 0;
		i[2] = 0;
		i[3] = 0;
	}
	return (0);
}
