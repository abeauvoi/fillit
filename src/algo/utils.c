/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:07:55 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/22 19:11:29 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

uint32_t		get_next_psquare(uint32_t limit)
{
	uint32_t	res;

	res = 2;
	while ((res * res) < limit)
		++res;
	return (res);
}

char			*grow_map(char *map, uint32_t *cur_size, t_tetri **list)
{
	char		*new_map;

	*cur_size = get_next_psquare(*cur_size * *cur_size);
	if (!(new_map = create_map(*cur_size)))
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
