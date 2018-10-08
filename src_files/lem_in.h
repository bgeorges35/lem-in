/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:24:18 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 18:44:35 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct	s_pipe
{
	int			r_1;
	int			r_2;
}				t_pipe;

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
}				t_room;

typedef struct	s_way
{
	int			*way;
	int			len;
	int			i;
}				t_way;

typedef struct	s_lem
{
	int			nb_lem;
	t_room		*room;
	t_way		*way;
	int			nb_room;
	t_pipe		*pipe;
	int			nb_pipe;
}				t_lem;

void			free_anthill(t_lem *anthill);
/*
**	find_all_ways.c
*/

int				add_room_way(t_lem *anthill, int *way, int *stack_pipe);
int				recursive_stack_way(t_lem *anthill, int *way, int *stack_pipe);
int				stack_ways(t_lem *anthill);

/*
**	algo_basics_functions.c
*/

int				is_pipe_unsed(int pipe, int *stack_pipe);
int				is_multi_same_room(int cmp, int *way);
int				find_len_way(int *way);
t_list			*add_way(int *way, int len);
int				init_way(t_lem *anthill);

/*
**	parse.c
*/

int				parse_infos(char **str, t_lem *anthill);
int				read_parse(char **str);

/*
**	display.c
*/

int				print_map(t_lem *anthill);
void			aff_lst_inttab(t_list *ways);
void			aff_inttab(int *tab, int len);
int				ft_display_solve(t_lem *anthill, int len);

/*
**	parse_room.c
*/

int				check_rooms(char *str, int i);
int				is_switch(char *str, int *i, int *start, int *end);
int				is_name_room(char *str, int *i, int tmp_index);

/*
**	check_room.c
*/

int				check_and_stack_rooms(char *str, int *i, t_lem *anthill);

/*
**	check_pipe.c
*/

int				check_and_stack_pipe(t_lem *anthill, char **str, int *i);

/*
**	parse_pipe.c
*/

int				check_pipe(t_lem *anthill, char **str, int i);

/*
**	lem.c
*/

int				parse_digit(char *str, int *i);

/*
**	basics_functions.c
*/

int				ft_isdigit_index(char *str, int *i);
int				is_new_line(char *str, int i);
int				is_space(char *str, int i);

/*
**	algo.c
*/

int				main_solver(t_lem *anthill, char *str);
int				check_save_combination(t_list *tmp, t_list *new);

/*
**	solver.c
*/

int				algo_solver(t_lem *anthill, t_list *ways);

/*
**	comments.c
*/
int				remove_comments(char **str);
int				add_comments(char **str, char *tmp);
int				add_way_lem(t_lem *anthill, t_list *way, int *i);
t_list			*sort_lst(t_list *ways);

/*
**	stock_pipe.c
*/
t_pipe			*stack_pipe(t_lem *anthill, char *str, int *i);

/*
**	stock_room.c
*/

int				create_room(t_lem *anthill, char *str, int *i);
int				check_same_name(t_lem *anthill);
int				check_same_coordinate(t_lem *anthill);

#endif
