/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:59:26 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/20 20:19:15 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int argc, char *argv[])
{
	t_fillit	data;

	if (argc != 2)
		ft_putendl("Usage:./fillit file/to/open");
	else
	{
		parse_file(&data, argv[1]);
	}
	return (0);
}
