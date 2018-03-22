/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 18:26:36 by nnangis           #+#    #+#             */
/*   Updated: 2017/07/04 19:59:45 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int					size_int(int nbr)
{
	int		i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static	int					ft_is_neg(char *tab, int n)
{
	tab[0] = '-';
	return (-n);
}

static	void				ft_ito_norm(char *tab, int n)
{
	int i;
	int tmp;
	int j;

	tmp = n;
	j = size_int(n);
	i = j - 1;
	tab[j] = '\0';
	if (n < 0)
	{
		tmp = ft_is_neg(tab, n);
		j--;
	}
	while (j > 0)
	{
		tab[i] = tmp % 10 + 48;
		tmp = tmp / 10;
		i--;
		j--;
	}
}

char						*ft_itoa(int n)
{
	char *tab;

	tab = (char*)malloc(sizeof(char) * size_int(n) + 1);
	if (tab == NULL)
		return (NULL);
	else if (n == -2147483648)
	{
		tab[0] = '-';
		tab[1] = '2';
		tab[2] = '1';
		tab[3] = '4';
		tab[4] = '7';
		tab[5] = '4';
		tab[6] = '8';
		tab[7] = '3';
		tab[8] = '6';
		tab[9] = '4';
		tab[10] = '8';
		tab[11] = '\0';
	}
	else
		ft_ito_norm(tab, n);
	return (tab);
}
