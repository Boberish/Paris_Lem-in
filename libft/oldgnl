/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:08:16 by jaylor            #+#    #+#             */
/*   Updated: 2017/01/27 15:02:25 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_begline(t_stat *beg, char **line)
{
	if (!line || !(beg->rest))
		return (-1);
	if (*(beg->rest) && (ft_strchr(beg->rest, '\n') != NULL))
	{
		*line = ft_strndup(beg->rest, (ft_strchr(beg->rest, '\n') - beg->rest));
		beg->tmp = beg->rest;
		beg->rest = ft_strdup(ft_strchr(beg->tmp, '\n') + 1);
		free(beg->tmp);
		return (1);
	}
	if ((beg->rl < BUFF_SIZE) && *(beg->rest))
	{
		*line = ft_strdup(beg->rest);
		beg->rest = NULL;
		return (1);
	}
	return (0);
}

int		ft_buffline(t_stat *beg, char *buff, char **line)
{
	if (!beg || !buff || !line)
		return (-1);
	if (*buff && (ft_strchr(buff, '\n') != NULL))
	{
		*line = ft_strndup(buff, (ft_strchr(buff, '\n') - buff));
		beg->rest = ft_strdup(ft_strchr(buff, '\n') + 1);
		return (1);
	}
	if (*buff && (beg->rl < BUFF_SIZE))
	{
		*line = ft_strdup(buff);
		beg->rest = NULL;
		return (1);
	}
	return (0);
}

void	conditions1(t_stat *beg, char *buff)
{
	if (!(beg->rest))
		beg->rest = ft_strdup(buff);
	else
	{
		beg->tmp = beg->rest;
		beg->rest = ft_strjoin(beg->tmp, buff);
		if (*beg->tmp)
			free(beg->tmp);
	}
}

void	conditions2(t_stat *beg, char *buff)
{
	beg->tmp = beg->rest;
	beg->rest = ft_strjoin(beg->tmp, buff);
	if (*beg->tmp)
		free(beg->tmp);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_stat	*beg;

	if (!(beg))
		beg = ft_memalloc(sizeof(t_stat));
	if (ft_begline(beg, line) == 1)
		return (1);
	while ((beg->rl = read(fd, buff, BUFF_SIZE)) || beg->rest)
	{
		if ((int)beg->rl == -1)
			return (-1);
		buff[beg->rl] = '\0';
		if (ft_strchr(buff, '\n') || beg->rl < BUFF_SIZE)
		{
			if (beg->rest)
			{
				conditions2(beg, buff);
				return (ft_begline(beg, line));
			}
			return (ft_buffline(beg, buff, line));
		}
		conditions1(beg, buff);
	}
	return (0);
}
