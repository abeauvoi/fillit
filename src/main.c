/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:59:26 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/22 18:12:29 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		main(int argc, char *argv[])
{
	t_fillit	data;

	if (argc != 2)
		ft_putendl("Usage:./fillit file/to/open");
	else
	{
		ft_bzero(&data, sizeof(data));
		data.letter = 'A';
		if (parse_file(&data, argv[1]) == -1)
			return (-1);
		algo(&data);
		free_list(&data.list);
	}
	return (0);
}
