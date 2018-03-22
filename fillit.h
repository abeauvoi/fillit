/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:12:17 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/22 19:11:45 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <inttypes.h>

# define PLACE 1
# define CLEAR 0

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
	uint32_t	nb_tetri;
	char		letter;
}				t_fillit;

int				parse_file(t_fillit *data, const char *path);
void			enqueue(t_tetri **list, t_tetri *entry);
void			free_list(t_tetri **list);
t_tetri			*create_tetri(uint32_t data, char letter);
char			*grow_map(char *map, uint32_t *cur_size, t_tetri **list);
void			algo(t_fillit *data);
uint32_t		get_next_psquare(uint32_t limit);
char			*create_map(uint32_t map_size);
void			putnbr_base(uint32_t val, int base);

#endif
