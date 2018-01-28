/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:18:38 by akorunsk          #+#    #+#             */
/*   Updated: 2017/11/24 16:23:34 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

int		field_size_initial(t_tetramino **d)
{
	int count;
	int f_size;

	count = 0;
	while (d[count] != NULL)
		count++;
	if (count == 1 && check_if_square(d[0]))
		return (2);
	if (count == 2 && !check_if_line(d[0]) && !check_if_line(d[1]))
	{
		recount_minimise(d, 4);
		return (3);
	}
	f_size = 4;
	while (f_size * f_size < count * 4)
		f_size++;
	recount_to(d, 4, f_size);
	return (f_size);
}

void	error(t_tetramino **t)
{
	free_tetrs(t);
	ft_putstr("error");
}

void	solution(t_tetramino **tetraminos)
{
	int		field_size;
	char	*res;
	int		code;

	field_size = field_size_initial(tetraminos);
	if (field_size == 2)
		return (output_square());
	code = 0;
	while (!code)
	{
		res = ft_memalloc(sizeof(char) * field_size * field_size + 1);
		if (!res)
			return (error(tetraminos));
		ft_memset(res, '.', field_size * field_size);
		code = fillit(res, tetraminos, field_size, 0);
		if (!code)
			free(res);
		recount(tetraminos, field_size);
		field_size++;
	}
	output_res(res, field_size - 1);
	free(res);
}

int		main(int argc, char **argv)
{
	t_tetramino	**tetraminos;

	if (argc == 2)
	{
		tetraminos = read_tetr(argv[1]);
		if (!tetraminos)
			ft_putstr("error\n");
		else
			solution(tetraminos);
		free_tetrs(tetraminos);
	}
	else
		ft_putstr("usage: ./fillit file_containing_tetriminos\n");
	return (0);
}
