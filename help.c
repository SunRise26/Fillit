/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:55:29 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/28 14:55:30 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	if (s == NULL || !(res = ft_newwords(s, c)))
		return (NULL);
	k = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		j = 0;
		while (s[i] != c && s[i] != '\0')
		{
			res[k][j] = s[i];
			++j;
			++i;
			if (s[i] == '\0' || s[i] == c)
				res[k++][j] = '\0';
		}
		if (s[i] == '\0')
			break ;
	}
	res[k] = 0;
	return (res);
}

char	**ft_newwords(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	res = (char**)malloc(sizeof(char*) * (ft_numofwords(s, c) + 1));
	if (!res)
		return (0);
	k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] != c && s[i] != '\0')
		{
			++j;
			++i;
			if (s[i] == '\0' || s[i] == c)
				res[k++] = (char*)malloc(sizeof(char) * (j + 1));
		}
		++i;
	}
	return (res);
}

int		ft_numofwords(char const *s, char c)
{
	int		i[4];

	i[0] = 0;
	i[2] = ft_strlen(s);
	while (s[i[0]] == c)
		++i[0];
	while (s[i[2]] == c)
		--i[2];
	i[2] -= i[0];
	i[0] = 0;
	i[1] = 1;
	while (i[0] < i[2])
	{
		i[3] = 0;
		while (s[i[0]] == c)
		{
			if (i[3] == 0)
				++i[1];
			i[3] = 1;
			++i[0];
		}
		++i[0];
	}
	return (i[1]);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_putendl(char const *s)
{
	int i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	write(1, "\n", 1);
}
