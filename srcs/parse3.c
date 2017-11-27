/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/26 17:22:06 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		comment_parse(t_room *r, int k)
{
	*r->comments = r->input[k];
	r->comments++;
	return (0);
}

int		if_valid2(t_room *r, char *space)
{
	int f;
	int f1;

	f = 0;
	f1 = 0;
	if (*space == '\0' || *(space + 1) == '\0')
	{
		ft_putstr_fd("Major error, room position problem!!!!!!!", 2);
		return (0);
	}
    space++;
	while (*space == ' ')
		space++;
	while (*space)
    {
		f1 = 1;
		if (ft_isdigit(*space) != 0)
		{
			if (f == 2)
			{
				ft_putstr_fd("Major error, too many room positions", 2);
            	return (0);
			}
			f = 1;
		}
		else if (*space == ' ' && f == 1)
			f = 2;
		else
		{
			ft_putstr_fd("Major error, room position problem!!!!!!!", 2);
            return (0);
		}
		space++;
    }
	if (f1 == 0)
	{	
		ft_putstr_fd("Major error, 2nd room position problem!", 2);
		return (0);
	}
	return (1);	
}

int     if_valid_con(t_room *r, int k)
{
    char    *space;
    int     f;

    f = 0;
    if ((space = ft_strchr(r->input[k], ' ')) == NULL)
        return (0);
    space++;
    while (*space)
    {
        if (f == 1 && *space == ' ')
            break;
        if (ft_isdigit(*space++) != 0)
            f = 1;
        else
            return (0);
    }
    space++;
    while (*space)
    {
        if (ft_isdigit(*space++) == 0)
            return (0);
    }
    return (1);
}

int		fix_connection(t_room *r)
{
	char	*hold;
	int		i;

	i = 0;
	while (r->connection[i])
	{	
		hold = ft_strchr(r->connection[i], '\0');
		*hold = '-';
		i++;
	}
	i = 0;
	while (r->rooms[i])
	{
		hold = ft_strchr(r->rooms[i], '\0');
		*hold = ' ';
		i++;
	}
	return (0);
}

int		print_input(t_room *r)
{
	int i;

	i = 0;
	ft_putnbr(r->ants);
    ft_putchar('\n');
    fix_connection(r);
    ft_putstr("##start\n");
  	while (i < r->r_len - 1)
	{
		ft_putstr(r->rooms[i++]);
		ft_putchar('\n');
	}
	ft_putstr("##end\n");
	ft_putstr(r->rooms[i]);
    ft_putchar('\n');
    ft_print2d(r->connection);
    ft_putchar('\n');
	if (ft_print2d(r->comments) != -1)
    	ft_putchar('\n');
  //ft_print2d(r->map);
  	return (0);
}

int		strip_space(char *str, int *j)
{
	while (*str == ' ')
		(*j)++;
	return (0);
}
