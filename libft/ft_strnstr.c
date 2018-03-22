/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:55:18 by nnangis           #+#    #+#             */
/*   Updated: 2017/07/04 20:00:53 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;

	i = 0;
	if (*little == '\0')
		return ((char*)big);
	if (ft_strlen(little) > ft_strlen(big)
			|| ft_strlen(little) > len)
		return (0);
	while (i + ft_strlen(little) < len + 1 && *big)
	{
		if (*big == *little && ft_memcmp((void*)big,
					(void*)little, ft_strlen(little)) == 0)
			return ((char*)big);
		big++;
		i++;
	}
	return (NULL);
}
