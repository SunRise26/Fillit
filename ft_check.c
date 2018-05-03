/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:58:42 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/13 18:56:56 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
}

void	ft_usage(void)
{
	write(1, "usage: ./fillit file_name\n", 26);
}

int		**ft_ch_tetr(char **file)
{
	int **res;

	if (ft_ch_num_of_hash(file) == 0)
		return (NULL);
	res = (int**)malloc(sizeof(int*) * (ft_num_of_tetr(file) + 1));
	if (res == 0)
		return (NULL);
	ft_comb(file, res);
	return (res);
}

int		main(int argc, char **argv)
{
	char	*file;
	char	**ar;

	if (argc != 2)
	{
		ft_usage();
		return (0);
	}
	if (!(file = ft_read(argv[1])))
		return (0);
	if (!(ar = ft_tetr_ar(file)))
		return (0);
	if (ft_ch_val(ft_ch_tetr(ar)) == 1)
		ft_alg(ar);
	else
		ft_error();
	return (0);
}
