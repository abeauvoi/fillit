/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:07:55 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/26 19:13:28 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

char			*grow_map(char *map, uint32_t *map_size, t_tetri **list)
{
	char		*new_map;

	*map_size += 1;
	if (!(new_map = create_map(*map_size)))
	{
		free_list(list);
		ft_putendl_fd("Cannot allocate more memory, exit...", 2);
		exit(EXIT_FAILURE);
	}
	free(map);
	return (new_map);
}

char			*create_map(uint32_t map_size)
{
	uint32_t	i;
	uint32_t	len;
	char		*map;

	i = 0;
	len = map_size * map_size + map_size;
	if (!(map = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		map[i] = '.';
		++i;
		if ((i + 1) % (map_size + 1) == 0)
			map[i++] = '\n';
	}
	return (map);
}

void			putnbr_base(uint32_t val, int base)
{
	char		buf[33];
	char		*a;

	buf[32] = 0;
	a = buf + 32;
	while (val > 0)
	{
		*(--a) = "01"[val & (base - 1)];
		val /= base;
	}
	ft_putendl(a);
}

void		scale_up(uint64_t *new_val, uint64_t mask, uint8_t line_count)
{
	*new_val += (mask << line_count);
}

void		scale_down(uint64_t *new_val, uint64_t mask, uint8_t line_count)
{
	*new_val += (mask >> line_count);
}

void			scale_values(t_tetri *list,
		void (*scale_ft)(uint64_t, uint64_t, uint8_t))
{
	uint64_t	mask;
	uint64_t	new_val;
	uint8_t		line_count;

	while (list)
	{
		mask = 1;
		new_val = 0;
		line_count = 1;
		while (list->tetrimino & mask)
		{
			new_val += mask;
			mask <<= 1;
		}
		while ((mask <<= 1) < list->tetrimino)
			if (list->tetrimino & mask)
			{
				scale_ft(&new_val, mask, line_count);
				if (!(list->tetrimino & (mask << 1)))
					++line_count;
			}
		if (list->tetrimino != 0xF)
			list->tetrimino = new_val;
		list = list->next;
	}
}
