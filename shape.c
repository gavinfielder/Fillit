/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:50:13 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/16 17:11:43 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include <stddef.h>

const unsigned short g_shapes[19] = {
	0xF000, 0x8888, 0x6C00, 0x8C40, 0x4C80,
	0xC600, 0xCC00, 0xC880, 0xE200, 0x44C0,
	0x8E00, 0x4E00, 0x4C40, 0xE400, 0x8C80,
	0x88C0, 0x2E00, 0xC440, 0xE800
};

unsigned short		horiz_shift(unsigned short shape, unsigned short x)
{
	const unsigned short	hshift_mask[] = {0xEEEE, 0xCCCC, 0x8888};

	if (x > 3)
		return (0x0000);
	if (x)
	{
		shape &= hshift_mask[(x - 1) & 3];
		shape >>= x;
	}
	return (shape);
}

unsigned short		vert_shift(unsigned short shape, unsigned short y)
{
	if (y > 3)
		return (0x0000);
	if (y)
	{
		shape >>= (4 * y);
	}
	return (shape);
}

unsigned short		overlaps(unsigned short tet1, unsigned short tet2)
{
	unsigned short	tet1_dim;
	unsigned short	tet2_dim;

	tet1_dim = TET_GET_X(tet1);
	tet2_dim = TET_GET_X(tet2);
	if (tet1_dim > tet2_dim)
	{
		tet2 = horiz_shift(tet2, tet1_dim - tet2_dim);
		if (!tet2)
			return (0);
	}
	else
	{
		tet1 = horiz_shift(tet1, tet2_dim - tet1_dim);
		if (!tet1)
			return (0);
	}
	tet1_dim = TET_GET_Y(tet1);
	tet2_dim = TET_GET_Y(tet2);
	if (tet1_dim > tet2_dim)
		tet2 = vert_shift(tet2, tet1_dim - tet2_dim);
	else
		tet1 = vert_shift(tet1, tet2_dim - tet1_dim);
	return (tet1 & tet2);
}

unsigned short		str_to_shape(char *data)
{
	unsigned short	shape;
	unsigned int	i;
	
	i = 0;
	shape = 0;
	while (i < 16)
	{
		shape <<= 1;
		shape |= (data[i] == '#');
		i++;
	}
	return (shape);
}

int					identify(char *data)
{
	unsigned short	shape;
	int				i;

	if (data == NULL)
		return (-2);
	i = -1;
	while (++i < 16)
		if (data[i] != '.' && data[i] != '#')
			return (-2);
	shape = str_to_shape(data);
	i = 0;
	while (!(shape & SHAPE_ROW1) && i++ < 4)
		shape <<= 4;
	i = 0;
	while (!(shape & SHAPE_COL1) && i++ < 4)
		shape <<= 1;
	i = -1;
	while (++i <= 18)
		if (shape == g_shapes[i])
			return (i);
	return (-1);
}
























