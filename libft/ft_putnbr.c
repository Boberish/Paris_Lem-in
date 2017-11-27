/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 12:36:20 by jaylor            #+#    #+#             */
/*   Updated: 2017/03/08 13:28:30 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	ft_putnbr(intmax_t n)
{
	intmax_t	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}*/
#include "libft.h"

void    ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        ft_putstr("-2147483648");
        return ;
    }
    if (n < 0)
    {
        n = -n;
        ft_putchar('-');
    }
    if (n < 10)
        ft_putchar(n + '0');
    else
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
}
