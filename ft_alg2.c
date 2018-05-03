/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:45:54 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/27 17:45:55 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_max_el(char **ar)
{
	int i;
	int j;
	int res;

	i = 0;
	res = ar[0][0] - 48;
	while (ar[i] != NULL)
	{
		j = 0;
		while (j < 8)
		{
			if (ar[i][j] - 48 > res)
				res = ar[i][j] - 48;
			++j;
		}
		++i;
	}
	return (res);
}

char	**ft_res_ar(char **ar)
{
	int		i;
	int		j;
	int		r;
	char	**res;

	r = ft_max_el(ar);
	if (!(res = (char**)malloc(sizeof(char*) * (r + 2))))
		return (NULL);
	i = 0;
	while (i <= r)
	{
		if (!(res[i] = (char*)malloc(sizeof(char) * (r + 2))))
			return (NULL);
		j = 0;
		while (j <= r)
		{
			res[i][j] = '.';
			++j;
		}
		res[i][j] = '\0';
		++i;
	}
	res[i] = NULL;
	return (res);
}

void	ft_fill_res(char **ar)
{
	char	**res;
	int		i;
	int		x;
	int		y;

	res = ft_res_ar(ar);
	i = 0;
	while (ar[i] != NULL)
	{
		x = 0;
		y = 1;
		while (y < 8)
		{
			res[ar[i][x] - 48][ar[i][y] - 48] = i + 65;
			x += 2;
			y += 2;
		}
		++i;
	}
	i = 0;
	while (res[i] != 0)
	{
		ft_putendl(res[i]);
		++i;
	}
}

void	ft_alg(char **file)
{
	char **ar;

	ar = ft_index_ar(file);
	main_goal(ar);
	ft_fill_res(ar);
}
