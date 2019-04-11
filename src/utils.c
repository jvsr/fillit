/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 15:55:46 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/27 12:20:47 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

#include <stdlib.h>

void	display_error(void)
{
	ft_putendl("error");
	exit(0);
}

void	print_map(t_etmap *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		ft_putendl((map->square)[i]);
		i++;
	}
}

char	set_char(int incr)
{
	static char ch;

	if (!ch)
		ch = 'A';
	ch += incr;
	return (ch);
}

void	check_save_points(int *s_x, int *s_y, int x, int y)
{
	if (*s_x == -1 || *s_y == -1)
	{
		*s_x = x;
		*s_y = y;
	}
}

int		check_extremes(int diff_x, int diff_y, t_etmap *tet_map)
{
	if (diff_x < 0 || diff_y < 0
	|| diff_x >= tet_map->width
	|| diff_y >= tet_map->width
	|| tet_map->square[diff_x][diff_y] != '.')
		return (1);
	return (0);
}
