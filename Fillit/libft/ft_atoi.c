/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnangis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:27:30 by nnangis           #+#    #+#             */
/*   Updated: 2017/07/04 21:51:09 by nnangis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(char *str)
{
	int		res;
	int		is_neg;

	res = 0;
	is_neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		is_neg = (*str == '-' ? -1 : 1);
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * is_neg);
}
