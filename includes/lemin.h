/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/27 12:51:27 by jaylor           ###   ########.fr       */
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
	char			**start;
	int				end;
	char			**input;
	char			**connection;
	char			**map;
	int				r_len;
	char			**comments;
	int				*bpath;
	int				short_dis;
}					t_room;

typedef struct		s_astar
{
	int				x;
	int				y;
	int				z;
	int				neighbor;
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

int					main(int argc, char **argv);
int					free_stuff(t_room *r, t_astar *a);
int					free_it(char **str);

/*
**	initialize.c
*/

int					initialize_structs(t_room *r);

/*
**	parse.c
*/

int					get_ants(t_room *r);
int					parse_start(t_room *r, int k);
int					which_one(t_room *r, int *k, int *i, int *j);
int					if_valid_room(t_room *r, int k);
int     			pick(t_room *r, int *k, int *i, int *f);

/*
**	parse2.c
*/

int					room_parse(t_room *r, int k, int *i);
int					move_end(t_room *r, int k);
int					connection_parse(t_room *r, int k, int *i);
int					found_start(t_room *r, int *k);
int					found_end(t_room *r, int *k, int *i);
int					check_dups(t_room *r, int k);

/*
**	parse3.c
*/

int     			comment_parse(t_room *r, int k);
int					if_valid2(t_room *r, char *space);
int					if_valid_con(t_room *r, int k);
int					fix_conneciton(t_room *r);
int					print_input(t_room *r);
int					strip_space(char *str, int *j);

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

/*
**	solver.c
*/

int     ft_caller(t_room *r);
int		solve(int *path, int y, int x, int z, int i, t_room *r);

/*
**	print_ants.c
*/

void		print_ants(t_room *r);
int     chop_at_space_gen(char *str);
int		line_print(int i, int j, t_room *r, int k);

/*
**	new_solver.c
*/

int		ft_lowest(int *array, int *inthis);
int		ft_remove(int rem, int *array);
int		ft_add(int add, int *array);
int		ft_in(int num, int *array);
int		ft_distance(t_room *r, int room_1, int room_2);
int		ft_Astar_init(t_room *r, t_astar *a);
int		ft_A_star(t_room *r, t_astar *a);
int		*ft_reconstruct(int *came_from, int current);
#endif
