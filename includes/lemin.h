/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 12:12:09 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/includes/libft.h"

typedef struct		s_room
{
	int				ants;
	char			**rooms;
	int				end;
	char			**input;
	char			**connection;
	char			**map;
	int				r_len;
	int				*bpath;
	char			*p;
	int				f;
}					t_room;

typedef struct		s_astar
{
	int				x;
	int				y;
	int				z;
	int				neb;
	int				current;
	int				ten_gscore;
	int				*closed_set;
	int				*open_set;
	int				*came_from;
	int				*gscore;
	int				*fscore;

}					t_astar;

/*
**	main.c
*/

int					main(void);
int					free_stuff(t_room *r, t_astar *a);
int					free_it(char **str);
int					ft_add(int add, int *array);
int					ft_in(int num, int *array);

/*
**	parse.c
*/

int					get_ants(t_room *r);
int					parse_start(t_room *r, int k);
int					which_one(t_room *r, int *k, int *i);
int					valid_room(t_room *r);
int					pick(t_room *r, int *k, int *i);

/*
**	parse2.c
*/

int					room_parse(t_room *r, int k, int *i);
int					move_end(t_room *r, int k);
int					found_start(t_room *r, int *k);
int					found_end(t_room *r, int *k, int *i);
int					check_dups(t_room *r, int k);

/*
**	parse3.c
*/

int					ft_error(char *mes, int ret);
int					ft_remove(int rem, int *array);
int					ft_distance(t_room *r, int room_1, int room_2);
int					connection_parse(t_room *r, int k);

/*
**	utilities.c
*/

int					init_rooms(t_room *r);
int					chop_at_space(t_room *r, int k);
int					init_map(t_room *r);
int					get_input(t_room *r, int fd);
int					ft_error_check(t_room *r);

/*
**	make_map.c
*/

int					add_con_to_map(t_room *r);
int					chomp_at_dash(t_room *r, int i);
int					add_con1(t_room *r, int *i);

/*
**	print_ants.c
*/

void				print_ants(t_room *r);
int					line_print(int i, int j, t_room *r, int k);

/*
**	new_solver.c
*/

int					ft_lowest(int *array, int *inthis);
int					ft_astar_init(t_room *r, t_astar *a);
int					ft_a_star(t_room *r, t_astar *a);
int					*ft_reconstruct(int *came_from, int current);
void				ft_a_star2(t_room *r, t_astar *a);

#endif
