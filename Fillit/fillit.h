/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:12:17 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/20 22:05:41 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <inttypes.h>

typedef struct	s_tetri
{
	int				tetrimino;
	char			letter;
	struct s_tetri	*next;
}				t_tetri;

typedef struct	s_fillit
{
	t_tetri		*list;
	char		*map;
	uint32_t	map_size;
}				t_fillit;

void			parse_file(t_fillit *data, const char *path);
void			enqueue(t_tetri **list, t_tetri *entry);
void			free_list(t_tetri **list);
t_tetri			*create_tetri(uint32_t data, char Letter);

#endif
