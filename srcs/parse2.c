/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 12:08:12 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		room_parse(t_room *r, int k, int *i)
{
	if (valid_room(r) == -1)
		return (-1);
	chop_at_space(r, k);
	if (check_dups(r, k) == -1)
		return (-1);
	r->rooms[(*i)++] = r->input[k];
	return (0);
}

int		check_dups(t_room *r, int k)
{
	int i;

	i = 0;
	if (r->rooms[i] == (char*)28)
		i++;
	while (r->rooms[i] != 0)
	{
		if (ft_strcmp(r->input[k], r->rooms[i]) == 0)
			return (ft_error("Major error, 2 room names are the same\n", -1));
		i++;
	}
	return (0);
}

int		move_end(t_room *r, int i)
{
	char	*tmp;

	tmp = r->rooms[i];
	r->rooms[i] = r->rooms[r->end];
	r->rooms[r->end] = tmp;
	r->end = i;
	return (1);
}

int		found_start(t_room *r, int *k)
{
	if (r->rooms[0] != (char*)28)
		return (ft_error("Major error, more than one start room found\n", -1));
	if (r->input[*k + 1] != 0)
		(*k)++;
	else
		return (ft_error("no start room\n", -1));
	while (r->input[*k][0] == '#')
		(*k)++;
	if ((r->p = ft_strchr(r->input[*k], ' ')) == NULL)
		return (ft_error("not a room after start\n", -1));
	if (valid_room(r) == -1)
		return (-1);
	chop_at_space(r, *k);
	r->rooms[0] = r->input[*k];
	return (1);
}

int		found_end(t_room *r, int *k, int *i)
{
	if (r->end != -1)
		ft_error("Major error, more than one end room found\n", -1);
	if (r->input[*k + 1] != 0)
		(*k)++;
	else
		return (ft_error("no end room\n", -1));
	while (r->input[*k][0] == '#')
		(*k)++;
	if ((r->p = ft_strchr(r->input[*k], ' ')) == NULL)
		return (ft_error("not a room after end\n", -1));
	if (valid_room(r) == -1)
		return (-1);
	chop_at_space(r, *k);
	r->end = *i;
	r->rooms[(*i)++] = r->input[*k];
	return (1);
}
