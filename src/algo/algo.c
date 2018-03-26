/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:00:31 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/26 19:18:27 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "fillit.h"

static void	place_tetri(int tetrimino, char *map, char mode, char letter)
{
	if (mode == PLACE)
		while (tetrimino > 0)
		{
			if (tetrimino & 1)
				*map = letter;
			tetrimino >>= 1;
			++map;
		}
	else
		while (tetrimino > 0)
		{
			if (tetrimino & 1)
				*map = '.';
			tetrimino >>= 1;
			++map;
		}
}

static int	can_place_tetri(char *map, int tetrimino)
{
	while (*map && tetrimino)
	{
		if ((*map == '\n' || *map != '.') && (tetrimino & 1) == 1)
			return (0);
		tetrimino >>= 1;
		++map;
	}
	return (tetrimino == 0);
}

static int	solve(int pos, char *map, t_tetri *list)
{
	if (list == NULL)
		return (1);
	if (map[pos] == 0)
		return (0);
	if (can_place_tetri(map + pos, list->tetrimino) == 1)
	{
		place_tetri(list->tetrimino, map + pos, PLACE, list->letter);
		ft_putendl(map);
		if (solve(0, map, list->next) == 1)
			return (1);
		place_tetri(list->tetrimino, map + pos, CLEAR, list->letter);
	}
	return (solve(pos + 1, map, list));
}

void		algo(t_fillit *data)
{
	if (data->nb_tetri == 1 && list->tetrimino == 99)
	{
		scale_values(data->list, scale_down);
		scale_values(data->list, scale_down);
	}
	data->map_size = 2;
	if (!(data->map = create_map(data->map_size)))
	{
		free_list(&data->list);
		ft_putendl_fd("Cannot allocate more memory, exit...", 2);
		exit(EXIT_FAILURE);
	}
	while (!solve(0, data->map, data->list))
	{
		data->map = grow_map(data->map, &data->map_size, &data->list);
		if (data->map_size > 4)
			scale_values(data->list, scale_up);
	}
	ft_putendl(data->map);
	free(data->map);
}
