/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 12:11:03 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_ants(t_room *r)
{
	int i;
	int k;
	int f;
	int ret;

	i = 0;
	k = 0;
	f = 0;
	while (r->input[k])
	{
		i = 0;
		ret = pick(r, &k, &i);
		if (ret == 1)
			break ;
		if (ret == -1)
			return (-1);
		k++;
	}
	r->ants = ft_atoi(r->input[k++]);
	if (parse_start(r, k) == -1)
		return (-1);
	return (0);
}

int		pick(t_room *r, int *k, int *i)
{
	while (r->input[*k][*i] == ' ')
		(*i)++;
	if (r->input[*k][*i] == '#')
		return (0);
	else
	{
		while (r->input[*k][*i] != '\0')
		{
			if (ft_isdigit(r->input[*k][*i]) == 0)
			{
				ft_putstr_fd("Major problem with number of ants\n", 2);
				return (-1);
			}
			(*i)++;
		}
		return (1);
	}
}

int		parse_start(t_room *r, int k)
{
	int		i;
	char	**nstart;
	int		bullshit;

	i = 1;
	nstart = r->connection;
	while (r->input[k])
	{
		bullshit = which_one(r, &k, &i);
		if (bullshit == -1)
			return (-1);
		if (bullshit == 2)
			break ;
		k++;
	}
	*r->connection = 0;
	r->connection = nstart;
	if (ft_error_check(r) == -1)
		return (-1);
	if (init_map(r) == -1)
		return (-1);
	move_end(r, --i);
	return (0);
}

int		which_one(t_room *r, int *k, int *i)
{
	if (r->input[*k][0] == 'L')
		return (ft_error("Major error, room name starts with L\n", -1));
	if (r->input[*k][0] == '#')
	{
		if (r->input[*k][1] == '#')
		{
			if (ft_strcmp(&r->input[*k][2], "start") == 0)
				return ((found_start(r, k)) ? 0 : -1);
			if (ft_strcmp(&r->input[*k][2], "end") == 0)
				return ((found_end(r, k, i)) ? 0 : -1);
		}
		return (0);
	}
	if ((r->p = ft_strchr(r->input[*k], '-')))
		return (connection_parse(r, *k));
	if ((r->p = ft_strchr(r->input[*k], ' ')))
		return (room_parse(r, *k, i));
	return (ft_error("non complaint or empty line\n", 2));
}

int		valid_room(t_room *r)
{
	int i;

	i = 0;
	r->f = 0;
	r->p = r->p + 1;
	while (r->p[i] != '\0')
	{
		if (ft_isdigit(r->p[i]) == 0)
		{
			if (i == 0)
				return (ft_error("ERROR, incorrect room pos\n", -1));
			else
			{
				r->f++;
				if (r->p[i] != ' ')
					return (ft_error("ERROR, incorrect room pos\n", -1));
				r->p = r->p + i + 1;
				i = -1;
			}
		}
		i++;
		if (r->f == 1 && i > 0 && r->p[i] == '\0')
			return (1);
	}
	return (ft_error("invalid room\n", -1));
}
