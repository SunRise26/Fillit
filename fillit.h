/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:16:33 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/28 13:00:21 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	**ft_bit_ar(char **file);
int		ft_len(char **file);
void	ft_error(void);
void	ft_usage(void);
int		ft_ch_val(int	**nums);
char	*ft_read(char *argv);
int		ft_ch_num_of_tetr(char *file);
int		ft_ch_symb(char *file);
int		ft_ch_lines(char *file);
int		ft_check(char *file);
char	**ft_tetr_ar(char *file);
int		ft_upcase(char a);
int		ft_ch_num_of_hash(char **file);
int		ft_num_of_tetr(char **file);
void	ft_print_comb(int **file);
int		**ft_comb(char **file, int **res);
int		**ft_ch_tetr(char **file);
int		ft_ch_valone(int *num);
void	ft_alg(char **file);
int		all_cmp(char **tetr);
int		maxx_ch(int max_sqr, char *tetr);
int		maxy_ch(int max_sqr, char *tetr);
int		tetr_cmp(char *tetr1, char *tetr2);
void	main_goal(char **tetr);
void	ft_x_shift(char *line, int n);
void	ft_y_shift(char *line, int n);
void	ft_fill_res(char **ar);
void	brute_force(char **tetr, int i, int ms, int ni);
char	**ft_index_ar(char **file);
int		case_a(char **tetr, int i, int ms);
void	tet_back(char *tetr, int flag);
int		ft_min_sqr(int tn);
size_t	ft_strlen(const char *str);
int		ft_numofwords(char const *s, char c);
char	**ft_newwords(char const *s, char c);
char	**ft_strsplit(char const *s, char c);
void	ft_putendl(char const *s);
int		case_b(char **tetr, int i, int ms);
int		switch_1(char **tetr, int *i, int ms, int *f);
void	switch_2(char **tetr, int *i, int ms, int *f);

#endif
