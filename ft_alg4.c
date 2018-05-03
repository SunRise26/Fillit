/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:48:59 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/27 17:49:00 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetr_cmp(char *tetr1, char *tetr2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (tetr1[i] == tetr2[j])
				if (tetr1[i + 1] == tetr2[j + 1])
					return (1);
			j += 2;
		}
		i += 2;
	}
	return (0);
}

int		all_cmp(char **tetr)
{
	int	i;
	int	j;

	i = 0;
	while (tetr[i + 1])
	{
		j = 0;
		while (tetr[j])
		{
			if (i == j)
				j++;
			if (tetr_cmp(tetr[i], tetr[j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_max_i(char **tetr)
{
	int	i;

	i = 0;
	while (tetr[i])
		i++;
	return (i);
}

int		maxx_ch(int max_sqr, char *tetr)
{
	int		i;

	i = 1;
	while (i < 8)
	{
		if (tetr[i] == max_sqr + 47)
			return (0);
		i += 2;
	}
	return (1);
}

int		maxy_ch(int max_sqr, char *tetr)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (tetr[i] == max_sqr + 47)
			return (0);
		i += 2;
	}
	return (1);
}
