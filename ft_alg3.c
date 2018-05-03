/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:48:54 by vveselov          #+#    #+#             */
/*   Updated: 2017/11/27 17:48:55 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tet_back(char *tetr, int flag)
{
	int		i;
	int		s;

	if (flag == 0)
	{
		i = 0;
		s = tetr[0];
		while (i < 8)
		{
			if (tetr[i] < s)
				s = tetr[i];
			i += 2;
		}
		ft_y_shift(tetr, -(s - 48));
	}
	i = 1;
	s = tetr[1];
	while (i < 8)
	{
		if (tetr[i] < s)
			s = tetr[i];
		i += 2;
	}
	ft_x_shift(tetr, -(s - 48));
}

int		ft_min_sqr(int tn)
{
	int	res;

	res = 0;
	tn *= 4;
	while (res * res < tn)
		res++;
	return (res);
}

int		case_a(char **tetr, int i, int ms)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		if (tetr_cmp(tetr[j], tetr[i]) == 1)
		{
			if (maxx_ch(ms, tetr[i]) == 1)
				ft_x_shift(tetr[i], 1);
			else
			{
				if (maxy_ch(ms, tetr[i]) == 1)
				{
					tet_back(tetr[i], 2);
					ft_y_shift(tetr[i], 1);
				}
				else
					return (0);
			}
			j = -1;
		}
	}
	return (1);
}

int		case_b(char **tetr, int i, int ms)
{
	int j;

	j = -1;
	if (maxx_ch(ms, tetr[i]) == 1)
		ft_x_shift(tetr[i], 1);
	else
	{
		if (maxy_ch(ms, tetr[i]) == 1)
		{
			tet_back(tetr[i], 2);
			ft_y_shift(tetr[i], 1);
		}
		else
			return (0);
	}
	while (++j < i)
		if (tetr_cmp(tetr[j], tetr[i]) == 1)
			return (2);
	return (1);
}
