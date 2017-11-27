/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:18:47 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/25 13:56:47 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	*ft_intdup(int *array)
{
	int *new;
	int i;
	
	i = 0;
	while (array[i] >= 0)
		i++;
	new = malloc(sizeof(int) * (i + 1));
	ft_intset(new, -1, i + 1);
	i = 0;
	while (array[i] != -1)
	{
	//	printf("i in ft_indup; %d\n", i);
		new[i] = array[i];
		i++;
	}
	return (new);
}
