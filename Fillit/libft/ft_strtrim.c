/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:55:50 by nnangis           #+#    #+#             */
/*   Updated: 2017/07/04 20:01:11 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_strlen_mod(char const *s)
{
	int	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;
	int		k;

	k = 0;
	i = 0;
	if (s == 0)
		return (NULL);
	j = (int)ft_strlen(s);
	i = ft_strlen_mod(s);
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n' || s[j] == '\0')
			&& j)
		j--;
	if (i == (int)ft_strlen(s) || i == j)
		i = -1;
	if ((str = (char*)malloc(sizeof(char) * (j - i + 2))) == 0)
		return (NULL);
	str[j + 1 - i] = '\0';
	while (i + k <= j)
	{
		str[k] = s[i + k];
		k++;
	}
	return (str);
}
