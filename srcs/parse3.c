/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 12:10:47 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_remove(int rem, int *array)
{
	int i;

	i = 0;
	while (array[i] != rem && array[i] != -1)
		i++;
	if (array[i] == -1)
		return (-1);
	while (array[i + 1] != -1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = -1;
	return (1);
}

int		ft_distance(t_room *r, int room_1, int room_2)
{
	int		i;
	char	*p;
	int		x[4];
	int		dist;
	int		j;

	i = 0;
	j = 0;
	while (r->rooms[room_1][j] != ' ')
		j++;
	p = &r->rooms[room_1][j + 1];
	x[0] = ft_atoi(p);
	x[1] = ft_atoi(p + ft_intlen(x[0]));
	j = 0;
	while (r->rooms[room_2][j] != ' ')
		j++;
	p = &r->rooms[room_2][j + 1];
	x[2] = ft_atoi(p);
	x[3] = ft_atoi(p + ft_intlen(x[2]));
	dist = ft_abs(x[2] - x[0]) + ft_abs(x[3] - x[1]);
	return (dist);
}

int		connection_parse(t_room *r, int k)
{
	if (ft_strchr(r->p + 1, '-') != NULL)
		return (ft_error("ERROR, 2 or more connections on one line\n", 2));
	*r->connection = r->input[k];
	r->connection++;
	return (0);
}

int		ft_error(char *mes, int ret)
{
	ft_putstr_fd(mes, 2);
	return (ret);
}
