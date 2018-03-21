/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:52:38 by nnangis           #+#    #+#             */
/*   Updated: 2017/07/04 23:03:59 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	de;

	i = 0;
	de = 0;
	while (dst[de] != '\0' && de < size)
		de++;
	while (src[i] != '\0' && i + de < size - 1 && size != 0)
	{
		dst[i + de] = src[i];
		i++;
	}
	if (de < size)
		dst[i + de] = '\0';
	return (de + ft_strlen(src));
}
