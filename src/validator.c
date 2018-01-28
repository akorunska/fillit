/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:42:34 by ddenkin           #+#    #+#             */
/*   Updated: 2017/11/24 16:13:19 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_square(char *tetr, int count)
{
	int		i;

	i = 0;
	if (count != 8)
		return (-count);
	while (tetr[i] != '\0')
	{
		if (tetr[i] == '#')
		{
			if (i <= 14 && tetr[i + 1] == '#' &&
					tetr[i + 5] == '#' && tetr[i + 6] == '#')
				return (1);
			else
				return (-count);
		}
		i++;
	}
	return (-count);
}

int			validate_tetr_h(char *tetr, t_tetramino *res, int count, int num)
{
	int		i;

	i = 0;
	while (tetr[i] != '\0')
	{
		if (tetr[i] == '.' || (tetr[i] == '\n' && i % 5 == 4))
			i++;
		else if (tetr[i] == '#')
		{
			res->coordinates[num++] = i;
			if (tetr[i + 1] == '#')
				count++;
			if (i >= 5 && tetr[i - 5] == '#')
				count++;
			if (i <= 16 && tetr[i + 5] == '#')
				count++;
			if (i >= 1 && tetr[i - 1] == '#')
				count++;
			i++;
		}
		else
			return (0);
	}
	return (count);
}

t_tetramino	*validate_tetr(char *tetr, int letter)
{
	int			count;
	t_tetramino *res;
	int			num;

	count = 0;
	num = 0;
	res = (t_tetramino *)malloc(sizeof(t_tetramino) + 1);
	if (validate_num(tetr) != 1 || res == NULL)
		return (NULL);
	count = validate_tetr_h(tetr, res, count, num);
	res->letter = letter;
	if (count == 6)
		return (res);
	else
		return (is_square(tetr, count) == 1 ? res : NULL);
}

int			validate_num(char *tetr)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tetr[i] != '\0')
	{
		if (i >= 20)
			return (-1);
		if (i % 5 == 4 && tetr[i] != '\n')
			return (-2);
		if (i % 5 != 4 && !(tetr[i] == '.' || tetr[i] == '#'))
			return (-3);
		if (tetr[i] == '#')
			count++;
		i++;
	}
	if (count == 4)
		return (1);
	return (-4);
}
