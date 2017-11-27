/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 09:04:12 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/12 09:38:13 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t		ft_atoi(const char *str)
{
	uintmax_t	num;
	int			index;
	int			ifneg;

	index = 0;
	while (str[index] == ' ' || str[index] == '\v' || str[index] == '\t' ||
			str[index] == '\r' || str[index] == '\n' || str[index] == '\f')
		index++;
	num = 0;
	ifneg = 1;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			ifneg = -1;
		index++;
	}
	while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9')
	{
		num = num * 10 + str[index] - '0';
		index++;
	}
	num = num * ifneg;
	return (num);
}
