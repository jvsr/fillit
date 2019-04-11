/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 14:23:02 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/27 12:20:17 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

#include <stdlib.h>

int		determine_map_start_width(t_etrominos *tet_lst)
{
	int i;
	int	result;

	i = 0;
	result = 0;
	while (tet_lst)
	{
		tet_lst = tet_lst->next;
		i += TET_SIZE;
	}
	while (!result)
	{
		result = ft_sqrt(i);
		i++;
	}
	return (result);
}

void	initialize_map(t_etmap *tet_map, int width)
{
	int i;
	int j;

	i = 0;
	(tet_map->square) = (char**)malloc(sizeof(char*) * (width + 1));
	if (!tet_map->square)
		display_error();
	while (i < width)
	{
		tet_map->square[i] = (char*)malloc(sizeof(char) * (width + 1));
		if (!tet_map->square[i])
			display_error();
		j = 0;
		while (j < width)
		{
			(tet_map->square)[i][j] = '.';
			j++;
		}
		(tet_map->square)[i][j] = '\0';
		i++;
	}
	(tet_map->square)[i] = NULL;
}

void	free_map(t_etmap *tet_map, int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		free((tet_map->square)[i]);
		i++;
	}
	free(tet_map->square);
}

t_etmap	*create_map(t_etrominos tet_lst)
{
	t_etmap	*tet_map;

	tet_map = (t_etmap*)malloc(sizeof(t_etmap));
	if (!tet_map)
		display_error();
	tet_map->width = determine_map_start_width(&tet_lst);
	initialize_map(tet_map, tet_map->width);
	while (!fill_map(tet_map, &tet_lst))
	{
		free_map(tet_map, tet_map->width);
		tet_map->width++;
		initialize_map(tet_map, tet_map->width);
	}
	return (tet_map);
}
