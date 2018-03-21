/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:55:30 by nnangis           #+#    #+#             */
/*   Updated: 2017/07/04 20:00:55 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					ft_count_word(char *str, char c)
{
	int		i;
	int		nbr;

	if (str == NULL || c == 0)
		return (0);
	i = 0;
	nbr = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			nbr++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (nbr);
}

static	unsigned int		ft_strle(const char *str, char c)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static int					normi(char const *s, int i, char c)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char						**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tab = NULL;
	if (s == NULL || c == 0 || (tab = (char**)malloc(sizeof(char*)
					* ft_count_word((char*)s, c) + 1)) == NULL)
		return (tab);
	tab[ft_count_word((char*)s, c)] = NULL;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			tab[j] = ft_strsub(s, i, ft_strle(&s[i], c));
			j++;
			i = normi(s, i, c);
		}
	}
	return (tab);
}
