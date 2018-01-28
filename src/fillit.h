/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:44:26 by ddenkin           #+#    #+#             */
/*   Updated: 2017/11/24 16:23:27 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_tetramino
{
	int			coordinates[4];
	char		letter;
}				t_tetramino;

int				fillit(char *field, t_tetramino **tetrs, int field_size,\
				int to_insert);
int				overflows_bottom(int f_size, t_tetramino *t, int shift);
int				ints_right(int f_size, t_tetramino *t, int shift);
t_tetramino		*validate_tetr(char *tetr, int letter);
int				validate_num(char *tetr);
t_tetramino		**read_tetr(char *fname);
int				check_if_square(t_tetramino *tetr);
int				check_if_line(t_tetramino *tetr);
void			recount(t_tetramino **tetrs, int from);
void			recount_minimise(t_tetramino **tetrs, int from);
void			recount_to(t_tetramino **tetrs, int from, int to);
void			output_res(char *field, int f_size);
void			output_square(void);
void			free_tetrs(t_tetramino **tetrs);
int				free_tetrsi(t_tetramino **tetrs);
#endif
