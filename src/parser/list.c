/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:31:04 by nnangis           #+#    #+#             */
/*   Updated: 2018/03/22 15:54:34 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

t_tetri		*create_tetri(uint32_t data, char letter)
{
	t_tetri	*new;

	if (!(new = (t_tetri *)malloc(sizeof(*new))))
		return (NULL);
	new->tetrimino = data;
	new->letter = letter;
	new->next = NULL;
	return (new);
}

void		enqueue(t_tetri **list, t_tetri *entry)
{
	t_tetri	*tmp;

	if (*list == NULL)
		*list = entry;
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = entry;
	}
}

void		free_list(t_tetri **list)
{
	t_tetri	*tmp;

	tmp = *list;
	while (tmp)
	{
		tmp = (*list)->next;
		free(*list);
		(*list) = tmp;
	}
}
