/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/27 14:35:47 by jaylor           ###   ########.fr       */
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
	if (get_input(r, fd) == -1)
		return (-1);
	if (get_ants(r) == -1)
		return (-1);
	if	(add_con_to_map(r) == -1)
		return (-1);
	print_input(r);
	ft_Astar_init(r, a);
	if (ft_A_star(r,a) == -1)
		return (-1);
	print_ants(r);
	free_stuff(r, a);		
	return (0);
}

int		free_stuff(t_room *r, t_astar *a)
{
	free_it(r->input);
	free(r->rooms);
	free(r->connection);
	free(r->comments);
	free(r->bpath);	
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

