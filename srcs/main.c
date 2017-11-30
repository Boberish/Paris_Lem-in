/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 12:11:49 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_room	*r;
	t_astar	*a;
	int		fd;

	fd = 0;
	a = (t_astar*)malloc(sizeof(t_astar));
	r = (t_room*)malloc(sizeof(t_room));
	init_rooms(r);
	if (get_input(r, fd) == -1)
		return (-1);
	ft_print2d(r->input);
	if (get_ants(r) == -1)
		return (-1);
	add_con_to_map(r);
	ft_astar_init(r, a);
	if (ft_a_star(r, a) == -1)
		return (-1);
	print_ants(r);
	free_stuff(r, a);
	return (0);
}

int		free_stuff(t_room *r, t_astar *a)
{
	free_it(r->input);
	free_it(r->map);
	free(r->rooms);
	free(r->connection);
	free(r->bpath);
	free(a->closed_set);
	free(a->open_set);
	free(a->gscore);
	free(a->fscore);
	free(a->came_from);
	free(a);
	free(r);
	return (0);
}

int		free_it(char **str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		free(str[i++]);
	free(str);
	return (0);
}

int		ft_add(int add, int *array)
{
	int i;

	i = 0;
	while (array[i] != -1)
		i++;
	array[i] = add;
	return (0);
}

int		ft_in(int num, int *array)
{
	int i;

	i = 0;
	while (array[i] != num && array[i] != -1)
		i++;
	if (array[i] == -1)
		return (0);
	else
		return (1);
}
