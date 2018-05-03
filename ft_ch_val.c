/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:42:15 by vveselov          #+#    #+#             */
/*   Updated: 2017/11/16 14:18:13 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_ch_valone(int *n)
{
	int	i[3];
	int	i1;

	i[0] = 0;
	while (i[0] < 6)
	{
		i[2] = 0;
		i1 = 0;
		i[1] = i1 + 1;
		while (i[1] < 8 && i[2] == 0)
		{
			if (n[i[0]] == n[i1])
				if (n[i[1]] - n[i[0] + 1] == -1 || n[i[1]] - n[i[0] + 1] == 1)
					i[2] = 1;
			if (n[i[0]] + 1 == n[i1])
				if (n[i[0] + 1] - n[i[1]] == 0)
					i[2] = 1;
			i[1] += 2;
			i1 += 2;
		}
		if (i[2] == 0)
			return (0);
		i[0] += 2;
	}
	return (1);
}

int		ft_ch_valone2(int maxx, int minx, int maxy, int miny)
{
	int	xl;
	int	yl;

	xl = maxx - minx;
	yl = maxy - miny;
	if (xl == yl && xl != 1)
		return (0);
	if (xl == 3 && xl - yl != 3)
		return (0);
	if (yl == 3 && yl - xl != 3)
		return (0);
	return (1);
}

int		ft_ch_valone1(int *n)
{
	int	mx[2];
	int	my[2];
	int	i;

	i = 0;
	mx[0] = 0;
	mx[1] = n[1];
	my[0] = 0;
	my[1] = n[0];
	while (i < 8)
	{
		if (n[i] > my[0])
			my[0] = n[i];
		if (n[i] < my[1])
			my[1] = n[i];
		if (n[i + 1] > mx[0])
			mx[0] = n[i + 1];
		if (n[i + 1] < mx[1])
			mx[1] = n[i + 1];
		i += 2;
	}
	if (ft_ch_valone2(mx[0], mx[1], my[0], my[1]) == 0)
		return (0);
	return (1);
}

int		ft_ch_val(int **nums)
{
	int		i;

	i = 0;
	if (nums == NULL)
		return (0);
	while (nums[i] != NULL)
		if (ft_ch_valone(nums[i++]) == 0)
			return (0);
	i = 0;
	while (nums[i] != NULL)
		if (ft_ch_valone1(nums[i++]) == 0)
			return (0);
	return (1);
}
