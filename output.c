/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrmart <andrmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:03:04 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/20 17:14:29 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>

void	write_tet_to_square(unsigned short tet, unsigned char square_size,
			char *square, char tet_letter)
{
	unsigned short	tet_shape;
	unsigned short	tet_x;
	unsigned short	tet_y;
	int				i;
	int				j;

	tet_shape = g_shapes[tet & TET_ID_MASK];
	tet_x = TET_GET_X(tet);
	tet_y = TET_GET_Y(tet);
	i = tet_y * (square_size + 1) + tet_x;
	j = 0;
	while (j < 16)
	{
		if (tet_shape & (1 << (15 - j)))
			square[i] = tet_letter;
		j++;
		if (j % 4 == 0)
			i += square_size + 1 - 3;
		else
			i++;
	}
}

void	print_square(unsigned short *tets, unsigned char num_tets,
			unsigned char square_size)
{
	char	*out;
	int		i;
	char	tet_letter;

	out = (char *)malloc((DATA_SIZE + 1) * sizeof(char));
	i = -1;
	while (++i < DATA_SIZE)
	{
		if (i % (square_size + 1) == (square_size))
			out[i] = '\n';
		else
			out[i] = '.';
	}
	out[DATA_SIZE] = '\0';
	i = -1;
	tet_letter = 'A';
	while (++i < num_tets)
	{
		if (in_x_bounds(tets[i], square_size) && in_y_bounds(tets[i],
					square_size))
			write_tet_to_square(tets[i], square_size, out, tet_letter++);
	}
	write(1, out, DATA_SIZE);
	free(out);
}
