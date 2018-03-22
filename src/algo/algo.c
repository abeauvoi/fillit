/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:00:31 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/22 19:48:26 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "fillit.h"

static void	place_tetri(int tetrimino, char *map, char mode, char chars[2])
{
	if (mode == PLACE)
		while (tetrimino > 0)
		{
			if (*map != '\n')
				*map = chars[tetrimino & 1];
			tetrimino >>= 1;
			++map;
		}
	else
		while (tetrimino > 0)
		{
			if (*map != '\n' && (tetrimino & 1) == 1)
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
	char	chars[2];

	if (list == NULL)
		return (1);
	if (map[pos] == 0)
		return (0);
	if (can_place_tetri(map + pos, list->tetrimino) == 1)
	{
		chars[0] = '.';
		chars[1] = list->letter;
		place_tetri(list->tetrimino, map + pos, PLACE, chars);
		ft_putendl(map);
		if (solve(0, map, list->next) == 1)
			return (1);
		place_tetri(list->tetrimino, map + pos, CLEAR, chars);
	}
	if (solve(pos + 1, map, list) == 1)
		return (1);
	return (0);
}

void		algo(t_fillit *data)
{
	data->map_size = get_next_psquare(data->nb_tetri * 4);
	if (!(data->map = create_map(data->map_size)))
	{
		free_list(&data->list);
		ft_putendl_fd("Cannot allocate more memory, exit...", 2);
		exit(EXIT_FAILURE);
	}
	while (!solve(0, data->map, data->list))
		data->map = grow_map(data->map, &data->map_size, &data->list);
	ft_putendl(data->map);
	free(data->map);
}
