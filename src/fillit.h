/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 12:10:15 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/27 12:35:28 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TET_SIZE 4
# define BLOCK_SIZE 4
# define MAX_TETROMINOS 26

typedef struct			s_etrominos
{
	char				blocks[BLOCK_SIZE][BLOCK_SIZE + 1];
	struct s_etrominos	*next;
}						t_etrominos;

typedef struct			s_etmap
{
	int					width;
	char				**square;
}						t_etmap;

/*
**	>>>>>>>>	PARSE_FUNCTIONS		<<<<<<<<
*/
t_etrominos				*create_tet(int fd);
t_etrominos				*initiate_tetrominos(int fd);
void					set_next(t_etrominos **tet_lst, t_etrominos **tmp);

/*
**	>>>>>>>>	VALIDATE_FUNCTIONS	<<<<<<<<
*/
int						validate_count(t_etrominos *tet);
void					validate_char(char c, int *count);
void					validate_tet(char tet[BLOCK_SIZE][BLOCK_SIZE + 1]);
int						validate_shape(char tet[BLOCK_SIZE][BLOCK_SIZE + 1]);
int						validate_hashtag(char tet[BLOCK_SIZE][BLOCK_SIZE + 1],
										int i, int j);

/*
**	>>>>>>>>	UTIL_FUNCTIONS		<<<<<<<<
*/
char					set_char(int incr);
void					display_error(void);
void					print_map(t_etmap *map);
void					check_save_points(int *s_x, int*s_y, int x, int y);
int						check_extremes(int diff_x, int diff_y,
										t_etmap *tet_map);

/*
**	>>>>>>>>	MAP_FUNCTIONS		<<<<<<<<
*/
t_etmap					*create_map(t_etrominos tet_lst);
void					free_map(t_etmap *tet_map, int width);
void					initialize_map(t_etmap *tet_map, int width);
int						determine_map_start_width(t_etrominos *tet_lst);

/*
**	>>>>>>>>	FILL_FUNCTIONS		<<<<<<<<
*/
int						fill_map(t_etmap *tet_map, t_etrominos *tet_lst);
int						if_dot(t_etmap *tet_map, t_etrominos *tet_lst,
								int i, int j);
void					clear_tet(t_etmap *tet_map, t_etrominos tet_lst,
									int i, int j);
void					set_in_map(t_etmap *tet_map, t_etrominos tet_lst,
									int i, int j);
int						fit_tet_on_map(t_etmap *tet_map, t_etrominos tet_lst,
										int i, int j);

#endif
