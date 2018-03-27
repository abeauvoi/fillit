/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:00:12 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/27 18:09:00 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "fillit.h"

static int	count_links(const char buf[22])
{
	int	i;
	int	links;

	i = 0;
	links = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if ((i + 1) < 20 && buf[i + 1] == '#')
				++links;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				++links;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				++links;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				++links;
		}
		i++;
	}
	if (links == 6 || links == 8)
		return (1);
	return (0);
}

static uint32_t	record_tetrimino(const char buf[22])
{
	int			i;
	int			j;
	uint32_t	tetrimino;

	i = 0;
	j = -1;
	tetrimino = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (j == -1)
				j = i;
			tetrimino |= (1 << (i - j));
		}
		++i;
	}
	return (tetrimino);
}

static uint32_t	is_valid(const char buf[22], int ret, int sharp, int dots)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (buf[i] != '.' && buf[i] != '#')
				return (-1U);
			else if (buf[i] == '#')
				++sharp;
			else if (buf[i] == '.')
				++dots;
		}
		else if (buf[i] != '\n')
			return (-1U);
		++i;
	}
	if ((ret == 21 && buf[i] != '\n')
			|| sharp != 4 || dots != 12 || !count_links(buf))
		return (-1U);
	return (record_tetrimino(buf));
}

int			parse_file(t_fillit *data, const char *path)
{
	int		fd;
	char	buf[22];
	t_tetri	*new;
	int		ret;
	int		save_ret;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (-1);
	ft_bzero(buf, 22);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		if (ft_strlen(buf) < 20 || (new = create_tetri(is_valid(buf, ret, 0, 0),
						data->letter++)) == 0 || new->tetrimino == -1U
				|| data->nb_tetri++ > 26)
		{
			free_list(&data->list);
			return (-1);
		}
		save_ret = ret;
		enqueue(&data->list, new);
		ft_bzero(buf, 21);
	}
	if (data->nb_tetri == 0 || close(fd) == -1 || save_ret != 20)
		return (-1);
	return (0);
}
