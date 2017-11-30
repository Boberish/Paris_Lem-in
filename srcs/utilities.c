/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 11:51:27 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		init_rooms(t_room *r)
{
	r->rooms = (char**)malloc(sizeof(char*) * 500000);
	ft_memset(r->rooms, 0, 500000);
	r->rooms[0] = (char*)28;
	r->input = (char**)malloc(sizeof(char*) * 1000000);
	ft_memset(r->input, 0, 1000000);
	r->connection = (char**)malloc(sizeof(char*) * 1000000);
	ft_memset(r->connection, 0, 1000000);
	r->end = -1;
	return (0);
}

int		chop_at_space(t_room *r, int k)
{
	char	*space;

	space = ft_strchr(r->input[k], ' ');
	*space = '\0';
	return (0);
}

int		init_map(t_room *r)
{
	int i;

	i = 0;
	r->map = (char**)malloc(sizeof(char*) * (r->r_len + 1));
	if (r->map == NULL)
	{
		ft_putstr_fd("Major error, no MALLOC FAILLED\n", 2);
		return (-1);
	}
	r->map[r->r_len] = 0;
	while (i < r->r_len)
	{
		r->map[i] = ft_strnew(r->r_len);
		ft_memset(r->map[i++], '0', r->r_len);
	}
	return (0);
}

int		get_input(t_room *r, int fd)
{
	char	*line;
	char	**start;

	start = r->input;
	while (get_next_line(fd, &line) > 0)
	{
		*r->input = ft_strdup(line);
		r->input++;
		free(line);
	}
	*r->input = 0;
	r->input = start;
	if (r->input[0] == 0)
	{
		ft_putstr_fd("Major error, no input\n", 2);
		return (-1);
	}
	return (0);
}

int		ft_error_check(t_room *r)
{
	if (r->end == -1)
		return (ft_error("Major error, no end room!\n", -1));
	if (r->rooms[0] == (char*)28)
		return (ft_error("Major error, no start room\n", -1));
	r->r_len = ft_list_len(r->rooms);
	if (r->r_len == 0)
		return (ft_error("Major error, no rooms!\n", 2));
	if (ft_list_len(r->connection) == 0)
		return (ft_error("Major error, no connections!\n", -1));
	return (0);
}
