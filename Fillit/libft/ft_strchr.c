/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 18:42:44 by nnangis           #+#    #+#             */
/*   Updated: 2017/07/04 20:00:23 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c == '\0')
		return (&(((char*)s)[ft_strlen(s)]));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char*)s)[i]);
		i++;
	}
	return (NULL);
}
