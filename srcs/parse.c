/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/27 12:11:01 by jaylor           ###   ########.fr       */
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
	r->start = NULL;
	while (r->input[k])
	{
		i = 0;
		ret = pick(r, &k, &i, &f);
		if (ret == 1)
			break;
		if (ret == -1)
			return (-1);
		k++;
	}
	r->ants = ft_atoi(r->input[k++]);
	if (parse_start(r, k) == -1)
		return (-1);
	return (0);
}

int		pick(t_room *r, int *k, int *i, int *f)
{
	while (r->input[*k][*i] == ' ')
		(*i)++;
	if (r->input[*k][*i] == '\0')
		return (0);
	else if (r->input[*k][*i] == '#')
	{
		if (*f == 0)
			r->start = r->comments;
		*f = 1;
		comment_parse(r, (*k));
	}
	else 
	{
		while (r->input[*k][*i] != '\0')
		{	
			if (ft_isdigit(r->input[*k][*i]) == 0)
			{
				ft_putstr_fd("Major problem with number of ants", 2);
				return (-1);
			}
			(*i)++;
		}
		return (1);
	}	
	return (0);
}

int		parse_start(t_room *r, int k)	
{
	int 	i;
	char 	**nstart;
	int		j;

	i = 1;
	j = 0;
	nstart = r->connection;
	if (r->start == NULL)
	   r->start = r->comments;
	while (r->input[k])
	{
		j = 0;
		if (which_one(r, &k, &i, &j) == -1)
			return (-1);
		k++;
	}
	*r->connection = 0;
	r->connection = nstart;
	r->comments = r->start;
	if (ft_error_check(r) == -1)
		return (-1);
	if (init_map(r) == -1)
		return (-1);
	move_end(r, --i);
	return (0);
}

int		which_one(t_room *r, int *k, int *i, int *j)
{
	while (r->input[*k][*j] == ' ')
		(*j)++;
	if (r->input[*k][*j] == 'L')
	{
		ft_putstr_fd("Major error, room name starts with L", 2);
		return (-1);
	}
	if (r->input[*k][*j] == '#')
	{
		if (r->input[*k][*j + 1] == '#')
		{
			if (ft_strcmp(&r->input[*k][*j + 2], "start") == 0)
				 return ((found_start(r, k)) ? 0 : -1);
			if (ft_strcmp(&r->input[*k][*j + 2], "end") == 0)
				 return ((found_end(r, k, i)) ? 0 : -1);
		}
		comment_parse(r, *k);
		return (0);
	}
	if (ft_strchr(r->input[*k], '-'))
		connection_parse(r, *k, i);
	if (ft_strchr(r->input[*k], ' '))
	{
		if (room_parse(r, *k, i) == -1)
			return (-1);
	}
	return (0);
}


int		ft_shitmove(t_room *r, int k, int j)
{
	int i;
	int save;
	int len;

	save = j;
	i = 0;
	len = ft_strlen(r->input[k]) - save;
	while (len--)
		r->input[k][i++] = r->input[k][j++];
	while (save--)
		r->input[k][i] = '\0';
	return (0);
}

int		if_valid_room(t_room *r, int k)
{
	char	*space;
	int		f;
	int 	j;

	j = 0;
	f = 0;
	while (r->input[k][j] == ' ')
		j++;
	ft_shitmove(r, k, j);
	if ((space = ft_strchr(&(r->input[k][j]), ' ')) == NULL)
	{	
		ft_putstr_fd("Major error, room position problem", 2);
		return (0);
	}
	space++;
	while (*space == ' ')
		space++;
	while (*space)
    {
		if (f == 1 && *space == ' ')
			break;
        if (ft_isdigit(*space++) != 0)
			f = 1;
		else
		{
			ft_putstr_fd("Major error, room position problem", 2);
            return (0);
		}
    }
	if (f == 0)
	{
		ft_putstr_fd("Major error, room position problem", 2);
		return (0);
	}
	if (if_valid2(r, space) == 0)
		return (0);
	return (1);
}
