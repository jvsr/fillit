/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 17:14:12 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/27 12:20:10 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fit_tet_on_map(t_etmap *tet_map, t_etrominos tet_lst, int i, int j)
{
	int x;
	int y;
	int s_x;
	int s_y;

	x = 0;
	s_x = -1;
	s_y = -1;
	while (x < BLOCK_SIZE)
	{
		y = 0;
		while (y < BLOCK_SIZE)
		{
			if ((tet_lst.blocks)[x][y] == '#')
			{
				check_save_points(&s_x, &s_y, x, y);
				if (check_extremes((i + (x - s_x)), (j + (y - s_y)), tet_map))
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

void	set_in_map(t_etmap *tet_map, t_etrominos tet_lst, int i, int j)
{
	int		x;
	int		y;
	int		s_x;
	int		s_y;
	char	ch;

	x = 0;
	s_x = -1;
	s_y = -1;
	ch = set_char(0);
	while (x < BLOCK_SIZE)
	{
		y = 0;
		while (y < BLOCK_SIZE)
		{
			if ((tet_lst.blocks)[x][y] == '#')
			{
				check_save_points(&s_x, &s_y, x, y);
				tet_map->square[i + (x - s_x)][j + (y - s_y)] = ch;
			}
			y++;
		}
		x++;
	}
}

void	clear_tet(t_etmap *tet_map, t_etrominos tet_lst, int i, int j)
{
	int x;
	int y;
	int s_x;
	int s_y;

	x = 0;
	s_x = -1;
	s_y = -1;
	while (x < BLOCK_SIZE)
	{
		y = 0;
		while (y < BLOCK_SIZE)
		{
			if ((tet_lst.blocks)[x][y] == '#')
			{
				check_save_points(&s_x, &s_y, x, y);
				tet_map->square[i + (x - s_x)][j + (y - s_y)] = '.';
			}
			y++;
		}
		x++;
	}
}

int		if_dot(t_etmap *tet_map, t_etrominos *tet_lst, int i, int j)
{
	set_char(0);
	if (fit_tet_on_map(tet_map, *tet_lst, i, j) == 1)
	{
		set_in_map(tet_map, *tet_lst, i, j);
		set_char(1);
		if (!(fill_map(tet_map, tet_lst->next)))
		{
			set_char(-1);
			clear_tet(tet_map, *tet_lst, i, j);
		}
		else
			return (1);
	}
	return (0);
}

int		fill_map(t_etmap *tet_map, t_etrominos *tet_lst)
{
	int			i;
	int			j;

	i = 0;
	if (!tet_lst)
		return (1);
	while (i < tet_map->width)
	{
		j = 0;
		while (j < tet_map->width)
		{
			if ((tet_map->square)[i][j] == '.')
			{
				if (if_dot(tet_map, tet_lst, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
