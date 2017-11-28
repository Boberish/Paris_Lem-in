/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/28 15:32:21 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	t_room	*r;
	t_astar	*a;
	int		fd;
	
	fd = open(argv[1], O_RDONLY);
	a = (t_astar*)malloc(sizeof(t_astar));
	r = (t_room*)malloc(sizeof(t_room));
	init_rooms(r);
	//ft_putstr("init rooms finished");
	if (get_input(r, fd) == -1)
		return (-1);
	//ft_putstr("get input finished");
	if (get_ants(r) == -1)
		return (-1);
	//ft_putstr("get ants finished");
	if	(add_con_to_map(r) == -1)
		return (-1);
	//ft_putstr("add con to map finished");
	print_input(r);
	//ft_putstr("print input finished");
	ft_Astar_init(r, a);
	if (ft_A_star(r,a) == -1)
		return (-1);
	print_ants(r);
	free_stuff(r, a);		/*
	char *line;

	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	free(line);	*/
	return (0);
}

int		free_stuff(t_room *r, t_astar *a)
{
	free_it(r->input);
	free_it(r->map);
	free(r->rooms);
	free(r->connection);
	free(r->comments);
	//free(r->start);
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

