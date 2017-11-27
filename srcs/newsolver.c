#include "lemin.h"


int		ft_Astar_init(t_room *r, t_astar *a)
{
	a->x = 0;
	a->y = 0;
	a->z = 0;
	a->current = 0;
	a->neighbor = 0;
	a->closed_set = (int*)malloc(sizeof(int) * 1000000);
	ft_memset(a->closed_set, -1, 1000000);
	a->open_set = (int*)malloc(sizeof(int) * 1000000);
	ft_memset(a->open_set, -1, 1000000);
	a->open_set[0] = 0;
	a->gscore = (int*)malloc(sizeof(int) * 1000000);
	ft_intset(a->gscore, 2147483647, 1000000);
	a->gscore[99999] = -1;
	a->gscore[0] = 0;
	a->fscore = (int*)malloc(sizeof(int) * 1000000);
	ft_intset(a->fscore, 2147483647, 1000000);
	a->fscore[9999] = -1;
	a->fscore[0] = ft_distance(r, 0, r->end);
	a->came_from = (int*)malloc(sizeof(int) * 1000000);
	ft_memset(a->came_from, -1, 1000000);
	return (0);
}

int		ft_A_star(t_room *r, t_astar *a)
{
	while (a->open_set[0] != -1)
	{
		a->current = ft_lowest(a->fscore, a->open_set);
		a->x = (a->z == 0) ? a->x : a->current;
		a->y = (a->z == 0) ? a->current : a->y;
		if (a->current == r->end)
		{
			r->bpath = (ft_reconstruct(a->came_from, a->current));
			return (0);
		}
		ft_remove(a->current, a->open_set);
		ft_add(a->current, a->closed_set);
		while (1)
		{	
			(a->z == 0) ? a->x++ : a->y++;
			while (a->x < r->r_len - 1 && a->y < r->r_len - 1 && r->map[a->x][a->y] == '0')
				(a->z == 0) ? a->x++ : a->y++;
			if (a->x > r->r_len - 1 || a->y > r->r_len - 1)
				break;
			if (r->map[a->x][a->y] != '1')
				break;
			a->neighbor = (a->z == 0) ?	a->x : a->y;
			if (ft_in(a->neighbor, a->closed_set) == 1)
				continue;
			if (ft_in(a->neighbor, a->open_set) == 0)
				ft_add(a->neighbor, a->open_set);
			a->ten_gscore = a->gscore[a->current] + ft_distance(r, a->current, a->neighbor);
			if (a->ten_gscore >= a->gscore[a->neighbor])
				continue;
			a->came_from[a->neighbor] = a->current;
			a->gscore[a->neighbor] = a->ten_gscore;
			a->fscore[a->neighbor] = a->gscore[a->neighbor] + ft_distance(r, a->neighbor, r->end);
			
		}
		a->y = 0;
		a->x = 0;
		a->z = (a->z == 0) ? 1 : 0;
	}	
	ft_putstr_fd("Major error, no solution to map", 2);
	return (-1);
}

int		*ft_reconstruct(int *came_from, int current)
{
	int		*path;

	path = (int*)malloc(sizeof(int) * 1000);
	ft_intset(path, -1, 1000);
	ft_add(current, path);
	while (came_from[current] != -1)
	{
		current = came_from[current];
		ft_add(current, path);
	}
	ft_intrev(path);
	return (path);
}

int		ft_lowest(int *array, int *inthis)
{
	int i;
	int low;
	int ret;
	
	low = 2147483647;	
	i = 0;
	while (inthis[i] != -1)
	{
		if (array[inthis[i]] < low)
		{
			low = array[inthis[i]];
			ret = inthis[i];
		}
		i++;
	}	
	return (ret);
}

int		ft_remove(int rem, int *array)
{
	int i;

	i = 0;
	while (array[i] != rem && array[i] != -1)
		i++;
	if (array[i] == -1)
		return (-1);
	while (array[i + 1] != -1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = -1;
	return (1);
}


int		ft_add(int add, int *array)
{
	int i;

	i = 0;
	while (array[i] != -1)
		i++;
	array[i] = add;
	return (0);
}

int		ft_in(int num, int *array)
{
	int i;

	i = 0;
	while (array[i] != num && array[i] != -1)
		i++;
	if (array[i] == -1)
		return (0);
	else
		return (1);
}

int		ft_distance(t_room *r, int room_1, int room_2)
{
 	int i;
    char *p;
    int *x;
    int dist;
	int j;

    i = 0;
	j = 0;
    x = (int*)malloc(sizeof(int) * 4);
	while (r->rooms[room_1][j] != ' ')
		j++;
	p = &r->rooms[room_1][j + 1];
		
	x[0] = ft_atoi(p);
	x[1] = ft_atoi(p + ft_intlen(x[0]));
	j = 0;
	while (r->rooms[room_2][j] != ' ')
		j++;
	p = &r->rooms[room_2][j + 1];
	x[2] = ft_atoi(p);
	x[3] = ft_atoi(p + ft_intlen(x[2]));
	dist = ft_abs(x[2] - x[0]) + ft_abs(x[3] - x[1]);
	free(x);
	return (dist);
}


