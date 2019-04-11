/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/01 11:47:33 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/27 12:19:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

t_etrominos	*create_tet(int fd)
{
	int			i;
	int			ret;
	t_etrominos	*tet;

	i = 0;
	tet = (t_etrominos*)malloc(sizeof(t_etrominos));
	if (tet == NULL)
		display_error();
	while (i < BLOCK_SIZE)
	{
		ret = read(fd, tet->blocks[i], BLOCK_SIZE + 1);
		if (ret != BLOCK_SIZE + 1 ||
			tet->blocks[i][BLOCK_SIZE] != '\n')
			display_error();
		tet->blocks[i][BLOCK_SIZE] = '\0';
		i++;
	}
	validate_tet(tet->blocks);
	tet->next = NULL;
	return (tet);
}

void		set_next(t_etrominos **tet_lst, t_etrominos **tmp)
{
	if ((*tet_lst) == NULL)
		*tet_lst = *tmp;
	else
	{
		(*tet_lst)->next = *tmp;
		*tet_lst = (*tet_lst)->next;
	}
}

t_etrominos	*initiate_tetrominos(int fd)
{
	int			ret;
	char		emp;
	t_etrominos	*tmp;
	t_etrominos	*tet_lst;
	t_etrominos	*first_address;

	emp = 0;
	tet_lst = NULL;
	first_address = NULL;
	tmp = create_tet(fd);
	if (!tmp)
		display_error();
	first_address = tmp;
	while (tmp)
	{
		set_next(&tet_lst, &tmp);
		ret = read(fd, &emp, 1);
		if (ret == 0)
			break ;
		if (emp != '\n' || ret < 0)
			display_error();
		tmp = create_tet(fd);
	}
	return (first_address);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_etmap		*final_map;
	t_etrominos	*tet_lst;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		display_error();
	tet_lst = initiate_tetrominos(fd);
	if (validate_count(tet_lst) > MAX_TETROMINOS)
		display_error();
	final_map = create_map(*tet_lst);
	print_map(final_map);
	close(fd);
	return (0);
}
