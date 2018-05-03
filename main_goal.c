/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_goal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:59:05 by vveselov          #+#    #+#             */
/*   Updated: 2017/11/30 18:03:41 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		switch_1(char **tetr, int *i, int ms, int *f)
{
	int c;

	tet_back(tetr[*i], 0);
	c = case_a(tetr, *i, ms);
	if (c == 0)
	{
		*f = 0;
		*i -= 1;
	}
	return (c);
}

void	switch_2(char **tetr, int *i, int ms, int *f)
{
	int c;

	c = case_b(tetr, *i, ms);
	if (c == 0)
		*i -= 1;
	else if (c == 1 && tetr[*i + 1])
	{
		*f = 1;
		*i += 1;
	}
}

void	brute_force(char **tetr, int i, int ms, int f)
{
	int c;

	if (!tetr[1])
		return ;
	while (1)
	{
		if (f == 1 && i != 0)
		{
			c = switch_1(tetr, &i, ms, &f);
			if (c == 1 && tetr[i + 1])
				i++;
			else if (c == 1 && !tetr[i + 1])
				return ;
		}
		if (f == 0 && i != 0)
			switch_2(tetr, &i, ms, &f);
		if (f == 0 && i == 0)
		{
			c = case_b(tetr, i, ms);
			if (c == 1 && ++i)
				f = 1;
			if (c == 0)
				return ;
		}
	}
}

void	main_goal(char **tetr)
{
	int		min_sqr;
	int		num_i;
	int		i;

	num_i = ft_num_of_tetr(tetr);
	min_sqr = ft_min_sqr(num_i);
	brute_force(tetr, 1, min_sqr, 1);
	while (all_cmp(tetr) == 1)
	{
		i = 0;
		while (tetr[i])
			tet_back(tetr[i++], 0);
		min_sqr++;
		brute_force(tetr, 1, min_sqr, 1);
	}
}
