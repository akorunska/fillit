/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:48:10 by akorunsk          #+#    #+#             */
/*   Updated: 2017/11/24 16:24:11 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	output_res(char *field, int f_size)
{
	int i;

	i = 0;
	while (i < f_size * f_size)
	{
		ft_putchar(field[i]);
		if ((i + 1) % f_size == 0)
			ft_putchar('\n');
		i++;
	}
}

void	output_square(void)
{
	ft_putstr("AA\nAA\n");
}
