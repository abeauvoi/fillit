/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:00:12 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/20 23:19:39 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

static void	count_links(const char buf[22])
{
	int	i;
	int	links;

	i = 0;
	links = 0;
	while (i < 20)
	{
		if (buf[i] == '#' && (((i + 1) < 20 && buf[i + 1] == '#')
					|| ((i - 1) >= 0 && buf[i - 1] == '#')
					|| ((i + 5) < 20 && buf[i + 5] == '#')
					|| ((i - 5) >= 0 && buf[i - 5] == '#')))
			++links;
		++i;
	}
	if (links == 6 || links == 8)
		return (1);
	return (0);
}

static int	is_valid(const char buf[22], int ret)
{
	int		tetri;
	int		i;
	int		first_occur;

	i = 0;
	tetri = 0;
	while (buf[i] != 0)
	{
		if (i % 5 < 4)
		{
			if (buf[i] != '.' && buf[i] != '#')
				return (-1);
			if (buf[i] == '#')
			{
				first_occur = i;
				tetri |= (1 << i);
			}
		}
		else if (buf[i] != '\n')
			return (-1);
		++i;
	}
}

int			parse_file(t_fillit *data, const char *path)
{
	int		fd;
	char	buf[22];
	t_tetri	*new;
	int		ret;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (-1);
	ft_bzero(buf, 22);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		if (ft_strlen(buf) < 20
				|| !(new = (t_tetri *)malloc(sizeof(*new)))
				|| (new->tetri = is_valid(buf, ret)) == -1
				|| data->nb_tetri > 26)
		{
			free_list(&data->list);
			exit(EXIT_FAILURE);
		}
		enqueue(&data->list, new);
		buf[20] = 0;
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}
