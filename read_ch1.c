/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ch1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:23:20 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/14 19:23:21 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(char *argv)
{
	int		fd;
	char	buf;
	int		i;
	char	*res;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, &buf, 1) > 0)
			++i;
		close(fd);
		res = (char*)malloc(sizeof(char) * (i + 2));
		if (res == NULL)
			return (NULL);
		i = 0;
		fd = open(argv, O_RDONLY);
		while (read(fd, &buf, 1) > 0)
			res[i++] = buf;
		res[i] = '\0';
		close(fd);
		return (res);
	}
	ft_error();
	return (NULL);
}

int		ft_ch_num_of_tetr(char *file)
{
	size_t	l;
	size_t	n;

	l = ft_strlen(file);
	if (!(file[l - 1] == 10 && (file[l - 2] == '.' || file[l - 2] == '#')))
		return (0);
	n = l / 20;
	if (l >= 440)
		n -= 1;
	if (n >= 1 && n <= 26)
		return (1);
	return (0);
}

int		ft_ch_symb(char *file)
{
	int i;

	i = 0;
	while (file[i] != '\0')
	{
		if (!(file[i] == '.' || file[i] == '#' || file[i] == '\n'))
			return (0);
		++i;
	}
	return (1);
}

int		ft_ch_lines(char *file)
{
	int i;
	int k;
	int n;

	i = 0;
	n = 4;
	k = 20;
	while (file[i] != '\0')
	{
		if (i == k)
		{
			if (file[i] != '\n')
				return (0);
			k += 21;
			n += 1;
		}
		else if (i == n)
		{
			if (file[i] != '\n')
				return (0);
			n += 5;
		}
		++i;
	}
	return (1);
}

int		ft_check(char *file)
{
	if (ft_ch_num_of_tetr(file) != 1)
		return (0);
	if (ft_ch_symb(file) != 1)
		return (0);
	if (ft_ch_lines(file) != 1)
		return (0);
	return (1);
}
