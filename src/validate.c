/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 16:03:38 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/27 12:21:07 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

void	validate_char(char c, int *count)
{
	if (c != '.' && c != '#')
		display_error();
	if (c == '#')
		(*count)++;
}

int		validate_hashtag(char tet[BLOCK_SIZE][BLOCK_SIZE + 1], int i, int j)
{
	int c;

	c = 1;
	tet[i][j] = '.';
	if (i > 0 && tet[i - 1][j] == '#')
		c += validate_hashtag(tet, i - 1, j);
	if (i < BLOCK_SIZE - 1 && tet[i + 1][j] == '#')
		c += validate_hashtag(tet, i + 1, j);
	if (j > 0 && tet[i][j - 1] == '#')
		c += validate_hashtag(tet, i, j - 1);
	if (j < BLOCK_SIZE - 1 && tet[i][j + 1] == '#')
		c += validate_hashtag(tet, i, j + 1);
	return (c);
}

int		validate_shape(char tet[BLOCK_SIZE][BLOCK_SIZE + 1])
{
	int		i;
	int		j;
	char	cpy[BLOCK_SIZE][BLOCK_SIZE + 1];

	i = 0;
	while (i < BLOCK_SIZE)
	{
		ft_strcpy(cpy[i], tet[i]);
		i++;
	}
	i = 0;
	while (i < BLOCK_SIZE)
	{
		j = 0;
		while (cpy[i][j])
		{
			if (cpy[i][j] == '#'
			&& validate_hashtag(cpy, i, j) != TET_SIZE)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	validate_tet(char tet[BLOCK_SIZE][BLOCK_SIZE + 1])
{
	int i;
	int j;
	int	count;

	i = 0;
	count = 0;
	while (i < BLOCK_SIZE)
	{
		j = 0;
		while (tet[i][j])
		{
			validate_char(tet[i][j], &count);
			j++;
		}
		i++;
	}
	if (count != TET_SIZE || !validate_shape(tet))
		display_error();
}

int		validate_count(t_etrominos *tet)
{
	int count;

	count = 0;
	while (tet)
	{
		tet = tet->next;
		count++;
	}
	return (count);
}
