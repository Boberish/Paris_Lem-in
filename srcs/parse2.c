/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/27 11:59:16 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		room_parse(t_room *r, int k, int *i)
{
	if (if_valid_room(r, k) == 0)
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
	while (r->rooms[i] != 0)
	{
		if (ft_strcmp(r->input[k], r->rooms[i]) == 0)
		{
			ft_putstr_fd("Major error, 2 room names are the same", 2);
			return (-1);
		}
		i++;
	}
	return (0);

}

int 	move_end(t_room *r, int i)
{
	char	*tmp;
	
	tmp = r->rooms[i]; 
	r->rooms[i] = r->rooms[r->end];
	r->rooms[r->end] = tmp;
	r->end = i;
	return (1);
}

int		connection_parse(t_room *r, int k, int *i)
{
	if (if_valid_con(r, k) == 1)
		room_parse(r, k, i);
	else
	{
		*r->connection = r->input[k];
		r->connection++;
	}
	return (0);
}

int		found_start(t_room *r, int *k)
{
	int i;

	i = 1;
	if (r->rooms[0] != (char*)28)
	{
 		ft_putstr_fd("Major error, more than one start room found", 2);	
		return (0);
	}
	while (r->input[*k + i][0] == '\0')
		i++;
	while (r->input[*k + i][0] == '#')
		comment_parse(r, (*k + i++));
	while (r->input[*k + i][0] == '\0')
		i++;
	*k = *k + i;
	if (if_valid_room(r, *k) == 0)
		return (0);
	chop_at_space(r, *k);
	r->rooms[0] = r->input[*k];
	return (1);
}

int		found_end(t_room *r, int *k, int *i)
{
	if (r->end != -1)
	{
 		ft_putstr_fd("Major error, more than one end room found", 2);	
		return (0);
	}
	while (r->input[++(*k)][0] == '#')
		comment_parse(r, *k);
	if (if_valid_room(r, *k) == 0)
		return (0);
	chop_at_space(r, *k);
	r->end = *i;
	r->rooms[(*i)++] = r->input[*k];
	return (1);
}
