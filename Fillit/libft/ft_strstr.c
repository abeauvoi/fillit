/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:55:38 by nnangis           #+#    #+#             */
/*   Updated: 2017/07/04 20:01:07 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*s;
	char	*to;

	if (*little == '\0')
		return ((char*)big);
	to = (char*)little;
	while (*big != '\0')
	{
		if (*big == *to)
		{
			s = (char*)big;
			while (*s == *to || *to == '\0')
			{
				if (*to == '\0')
					return ((char*)big);
				s++;
				to++;
			}
			to = (char*)little;
		}
		big++;
	}
	return (0);
}
