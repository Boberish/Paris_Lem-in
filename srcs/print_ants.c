#include "lemin.h"

void		print_ants(t_room *r)
{
	int i;
	int j;
	int k;
	int f;

	f = 0;
	k = ft_int_array_len(r->bpath) - 1;
	i = 1;
	j = 1;
	while (k--)
		chop_at_space_gen(r->rooms[r->bpath[i++]]);
	k = ft_int_array_len(r->bpath) - 1;
//	while (k--)
//		ft_printf("%s-> ",r->rooms[r->bpath[i++]]);
	k = ft_int_array_len(r->bpath) - 1;
	i = 1;
	while (1) 
	{
		i = 1;
		while (i < j)
		{
			f = 1;
			if (line_print(i, j - (i), r, k)  == 1)
				return;
			i++;
		}
		if (f == 1)
			ft_putchar('\n');
		j++;	
	}
}

int     chop_at_space_gen(char *str)
{
    char    *space;

    space = ft_strchr(str, ' ');
    *space = '\0';
	return (0);
}

int		line_print(int i, int j, t_room *r, int k)
{
	if ((j > k || i >= r->ants + 1) )
	{
		if (j > k && i >= r->ants)
			return (1);
		return (0);
	}
//	ft_printf("L%d-%s ", i, r->rooms[r->bpath[j]]);
	ft_putchar('L');
	ft_putnbr(i);
	ft_putchar('-');
	ft_putstr(r->rooms[r->bpath[j]]);
	ft_putchar(' ');
	return (2);
}
