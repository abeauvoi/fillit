/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:12:17 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/27 18:07:58 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <inttypes.h>

# define PLACE 1
# define CLEAR 0

typedef struct	s_tetri
{
	uint64_t		tetrimino;
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
uint32_t		resize_map(uint32_t limit, t_tetri *list);
char			*create_map(uint32_t map_size);
void			scale_values(t_tetri *list,
		void (*scale_ft)(uint64_t *, uint64_t, uint8_t));
void			scale_up(uint64_t *new_val, uint64_t mask, uint8_t line_count);
void			scale_down(uint64_t *new_val, uint64_t mask,
		uint8_t line_count);

#endif
