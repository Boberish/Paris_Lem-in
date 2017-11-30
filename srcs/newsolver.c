/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 11:51:37 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_astar_init(t_room *r, t_astar *a)
{
	a->x = 0;
	a->y = 0;
	a->z = 0;
	a->current = 0;
	a->neb = 0;
	a->closed_set = (int*)malloc(sizeof(int) * 1000000);
	ft_memset(a->closed_set, -1, 1000000);
	a->open_set = (int*)malloc(sizeof(int) * 1000000);
	ft_memset(a->open_set, -1, 1000000);
	a->open_set[0] = 0;
	a->gscore = (int*)malloc(sizeof(int) * 1000000);
	ft_intset(a->gscore, 2147483647, 1000000);
	a->gscore[99999] = -1;
	a->gscore[0] = 0;
	a->fscore = (int*)malloc(sizeof(int) * 1000000);
	ft_intset(a->fscore, 2147483647, 1000000);
	a->fscore[9999] = -1;
	a->fscore[0] = ft_distance(r, 0, r->end);
	a->came_from = (int*)malloc(sizeof(int) * 1000000);
	ft_memset(a->came_from, -1, 1000000);
	return (0);
}

int		ft_a_star(t_room *r, t_astar *a)
{
	while (a->open_set[0] != -1)
	{
		a->current = ft_lowest(a->fscore, a->open_set);
		a->x = (a->z == 0) ? a->x : a->current;
		a->y = (a->z == 0) ? a->current : a->y;
		if (a->current == r->end)
		{
			r->bpath = (ft_reconstruct(a->came_from, a->current));
			return (0);
		}
		ft_remove(a->current, a->open_set);
		ft_add(a->current, a->closed_set);
		ft_a_star2(r, a);
		a->y = 0;
		a->x = 0;
		a->z = (a->z == 0) ? 1 : 0;
	}
	ft_putstr_fd("Major error, no solution to map\n", 2);
	return (-1);
}

void	ft_a_star2(t_room *r, t_astar *a)
{
	while (1)
	{
		(a->z == 0) ? a->x++ : a->y++;
		while (a->x < r->r_len - 1 && a->y < r->r_len - 1
			&& r->map[a->x][a->y] == '0')
			(a->z == 0) ? a->x++ : a->y++;
		if (a->x > r->r_len - 1 || a->y > r->r_len - 1)
			break ;
		if (r->map[a->x][a->y] != '1')
			break ;
		a->neb = (a->z == 0) ? a->x : a->y;
		if (ft_in(a->neb, a->closed_set) == 1)
			continue;
		if (ft_in(a->neb, a->open_set) == 0)
			ft_add(a->neb, a->open_set);
		a->ten_gscore = a->gscore[a->current] +
		ft_distance(r, a->current, a->neb);
		if (a->ten_gscore >= a->gscore[a->neb])
			continue;
		a->came_from[a->neb] = a->current;
		a->gscore[a->neb] = a->ten_gscore;
		a->fscore[a->neb] = a->gscore[a->neb] + ft_distance(r, a->neb, r->end);
	}
}

int		*ft_reconstruct(int *came_from, int current)
{
	int		*path;

	path = (int*)malloc(sizeof(int) * 1000);
	ft_intset(path, -1, 1000);
	ft_add(current, path);
	while (came_from[current] != -1)
	{
		current = came_from[current];
		ft_add(current, path);
	}
	ft_intrev(path);
	return (path);
}

int		ft_lowest(int *array, int *inthis)
{
	int i;
	int low;
	int ret;

	low = 2147483647;
	i = 0;
	while (inthis[i] != -1)
	{
		if (array[inthis[i]] < low)
		{
			low = array[inthis[i]];
			ret = inthis[i];
		}
		i++;
	}
	return (ret);
}
