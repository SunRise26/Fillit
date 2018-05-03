/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:24:26 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/14 19:24:27 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tetr_ar(char *file)
{
	int		i[2];
	char	l;
	char	**res;

	if (ft_check(file) != 1)
	{
		ft_error();
		return (NULL);
	}
	i[0] = -1;
	i[1] = 20;
	l = 'A';
	while (file[++i[0]] != '\0')
	{
		if (file[i[0]] == '#')
			file[i[0]] = l;
		if (i[0] == i[1])
		{
			file[i[0]] = '*';
			i[1] += 21;
			++l;
		}
	}
	res = ft_strsplit(file, '*');
	return (res);
}

int		ft_upcase(char a)
{
	if (a >= 'A' && a <= 'Z')
		return (1);
	return (0);
}

int		ft_ch_num_of_hash(char **file)
{
	int i;
	int j;
	int k;
	int ch;

	i = -1;
	while (file[++i] != 0)
	{
		j = -1;
		k = 0;
		ch = 0;
		while (file[i][++j] != '\0')
		{
			if (j == ch + 5 && ft_upcase(file[i][j]) == 0 && ch != 0 && k < 4)
				return (0);
			if (ft_upcase(file[i][j]) == 1)
			{
				ch = j;
				++k;
			}
		}
		if (k != 4)
			return (0);
	}
	return (1);
}

int		ft_num_of_tetr(char **file)
{
	int i;

	i = 0;
	while (file[i] != NULL)
		++i;
	return (i);
}

int		**ft_comb(char **file, int **res)
{
	int i[5];

	i[0] = -1;
	i[3] = -1;
	while (file[++i[0]] != 0)
	{
		i[1] = -1;
		i[2] = 0;
		i[4] = 0;
		if (!(res[++i[3]] = (int*)malloc(sizeof(int) * 8)))
			return (0);
		while (file[i[0]][++i[1]] != '\0')
		{
			if (i[1] == 4 || i[1] == 9 || i[1] == 14)
				++i[2];
			if (ft_upcase(file[i[0]][i[1]]) == 1)
			{
				res[i[3]][i[4]++] = i[2];
				res[i[3]][i[4]++] = (i[1] - i[2]) % 4;
			}
		}
	}
	res[++i[3]] = 0;
	return (res);
}
