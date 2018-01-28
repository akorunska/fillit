/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:21:07 by ddenkin           #+#    #+#             */
/*   Updated: 2017/11/24 16:19:29 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			normalize_tetr(t_tetramino *tetr)
{
	int		xshift;
	int		yshift;
	int		i;

	xshift = -1;
	yshift = -1;
	i = -1;
	while (++i < 4)
	{
		if (xshift == -1)
			xshift = tetr->coordinates[i] % 5;
		else if (xshift > (tetr->coordinates[i] % 5))
			xshift = tetr->coordinates[i] % 5;
		if (yshift == -1)
			yshift = tetr->coordinates[i] / 5;
		else if (yshift > (tetr->coordinates[i] / 5))
			yshift = tetr->coordinates[i] / 5;
	}
	i = -1;
	while (++i < 4)
	{
		tetr->coordinates[i] -= xshift;
		tetr->coordinates[i] -= yshift * 5;
		tetr->coordinates[i] -= tetr->coordinates[i] / 5;
	}
}

int				read_tetr_h(int ret, int fd, char *buf, t_tetramino **res)
{
	int		hasnext;
	int		i;

	i = 0;
	hasnext = 1;
	while ((ret = read(fd, buf, 20)) != 0 || hasnext == 1)
	{
		buf[20] = '\0';
		if (ret != 20 || i > 25)
			return (0);
		if ((res[i] = validate_tetr(buf, i + 'A')) == NULL)
			return (free_tetrsi(res));
		else
		{
			normalize_tetr(res[i]);
			i++;
		}
		ret = read(fd, buf, 1);
		hasnext = (ret == 1 ? 1 : 0);
		if (hasnext == 1 && buf[0] != '\n')
			return (0);
	}
	res[i] = NULL;
	return (1);
}

t_tetramino		**read_tetr(char *fname)
{
	int			fd;
	int			ret;
	t_tetramino **res;
	char		buf[21];

	ret = 0;
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (!(res = (t_tetramino **)malloc(sizeof(t_tetramino *) * 27)))
		return (NULL);
	if (read_tetr_h(ret, fd, buf, res) != 1)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (res);
}
