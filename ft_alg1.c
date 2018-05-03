/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:04:45 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/15 19:04:46 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_min_val(int *ar, int *res)
{
	int i;
	int j;

	i = 0;
	j = 1;
	res[0] = ar[0];
	res[1] = ar[1];
	while (j < 8)
	{
		if (ar[i] < res[0])
			res[0] = ar[i];
		if (ar[j] < res[1])
			res[1] = ar[j];
		j += 2;
		i += 2;
	}
	return (res);
}

int		**ft_move(char **file)
{
	int **res;
	int r[2];
	int j;
	int k;
	int i;

	res = (int**)malloc(sizeof(int*) * (ft_num_of_tetr(file) + 1));
	if (res == 0)
		return (NULL);
	ft_comb(file, res);
	i = -1;
	while (res[++i])
	{
		j = 0;
		k = 1;
		ft_min_val(res[i], r);
		while (j < 8)
		{
			res[i][j] -= r[0];
			res[i][k] -= r[1];
			k += 2;
			j += 2;
		}
	}
	return (res);
}

char	**ft_index_ar(char **file)
{
	char	**res;
	int		**ar;
	int		i;
	int		j;

	if (!(res = (char**)malloc(sizeof(char*) * (ft_num_of_tetr(file) + 1))))
		return (NULL);
	ar = ft_move(file);
	i = 0;
	while (ar[i])
	{
		j = 0;
		res[i] = (char*)malloc(sizeof(char) * 9);
		while (j < 8)
		{
			res[i][j] = ar[i][j] + '0';
			++j;
		}
		res[i][j] = '\0';
		++i;
	}
	res[i] = 0;
	return (res);
}

void	ft_y_shift(char *line, int n)
{
	int i;

	i = 0;
	while (i < 8)
	{
		line[i] += n;
		i += 2;
	}
}

void	ft_x_shift(char *line, int n)
{
	int i;

	i = 1;
	while (i < 8)
	{
		line[i] += n;
		i += 2;
	}
}
