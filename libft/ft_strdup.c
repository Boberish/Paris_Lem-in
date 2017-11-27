/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:56:01 by jaylor            #+#    #+#             */
/*   Updated: 2016/11/30 13:19:05 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dupl;
	int		i;

	i = 0;
	if (s1 == NULL)
		return ((char*)s1);
	while (s1[i])
		i++;
	dupl = (char*)malloc(sizeof(*dupl) * (i + 1));
	if (dupl != 0)
		ft_strcpy(dupl, s1);
	return (dupl);
}
