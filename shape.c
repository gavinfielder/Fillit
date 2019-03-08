/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrmart <andrmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:50:13 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/21 13:38:03 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const unsigned short g_shapes[19] = {
	0xF000, 0x8888, 0x6C00, 0x8C40, 0x4C80,
	0xC600, 0xCC00, 0xC880, 0xE200, 0x44C0,
	0x8E00, 0x4E00, 0x4C40, 0xE400, 0x8C80,
	0x88C0, 0x2E00, 0xC440, 0xE800
};

static unsigned short		horiz_shift(unsigned short shape, unsigned short x)
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

static unsigned short		vert_shift(unsigned short shape, unsigned short y)
{
	if (y > 3)
		return (0x0000);
	if (y)
	{
		shape >>= (4 * y);
	}
	return (shape);
}

static unsigned short		str_to_shape(char *data)
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

unsigned short				overlaps(unsigned short tet1, unsigned short tet2)
{
	unsigned short	tet1_shape;
	unsigned short	tet2_shape;

	tet1_shape = g_shapes[tet1 & TET_ID_MASK];
	tet2_shape = g_shapes[tet2 & TET_ID_MASK];
	if ((tet1 & TET_X_MASK) > (tet2 & TET_X_MASK))
	{
		if (!(tet1_shape = horiz_shift(tet1_shape,
				(((tet1 & TET_X_MASK) - (tet2 & TET_X_MASK)) >> TET_X_SHFT))))
			return (0);
	}
	else
	{
		if (!(tet2_shape = horiz_shift(tet2_shape,
				(((tet2 & TET_X_MASK) - (tet1 & TET_X_MASK)) >> TET_X_SHFT))))
			return (0);
	}
	if ((tet1 & TET_Y_MASK) > (tet2 & TET_Y_MASK))
		tet1_shape = vert_shift(tet1_shape,
				(((tet1 & TET_Y_MASK) - (tet2 & TET_Y_MASK)) >> TET_Y_SHFT));
	else
		tet2_shape = vert_shift(tet2_shape,
				(((tet2 & TET_Y_MASK) - (tet1 & TET_Y_MASK)) >> TET_Y_SHFT));
	return (tet1_shape & tet2_shape);
}

int							identify(char *data)
{
	unsigned short	shape;
	int				i;

	if (data == NULL)
		return (INVALID_SHAPE);
	i = -1;
	while (++i < 16)
		if (data[i] != '.' && data[i] != '#')
			return (INVALID_SHAPE);
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
	return (INVALID_SHAPE);
}
