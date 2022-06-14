/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:39:55 by amateo-r          #+#    #+#             */
/*   Updated: 2021/11/08 16:39:56 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libsl.h"

/**
 * Display characters map of param 'map'.
 * @param	t_map	*map	Data of filename.map.
 */
void	print_map(char *fn, t_map *map)
{
	int	x;
	int	y;
	int	row;
	int	col;

	row = ft_rows(fn);
	col = ft_columns(fn);
	x = -1;
	while (++x < row)
	{
		y = -1;
		while (++y < col)
			printf("%c", map->board[x][y]);
		printf ("\n");
	}
	return ;
}

/*	Returns number of columns. */
size_t	ft_columns(char *fn)
{
	int		fd;
	size_t	col;
	char	c;

	fd = open(fn, O_RDONLY);
	col = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
		col++;
	return (col);
}

/*	Returns number of rows. */
size_t	ft_rows(char *fn)
{
	int		fd;
	char	c;
	size_t	row;

	fd = open(fn, O_RDONLY);
	row = 0;
	while (read(fd, &c, 1) != 0)
		if (c == '\n')
			row++;
	return (row);
}
