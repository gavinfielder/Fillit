/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:54:44 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/17 18:10:34 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"
#include "shape.h"
#include "testing.h"

void				set_pos(unsigned short *tet,
						unsigned short x, unsigned short y)
{
	*tet &= ~TET_X_MASK;
	*tet &= ~TET_Y_MASK;
	*tet |= (x << TET_X_SHFT);
	*tet |= (y << TET_Y_SHFT);
}

int					in_x_bounds(unsigned short tet, unsigned char grid_size)
{
	const unsigned short	border_mask[] = {0x1111, 0x3333, 0x7777};
	int						free_columns;

	free_columns = 0;
	while (free_columns < 3 && ((g_shapes[tet & TET_ID_MASK] & border_mask[free_columns]) == 0))
		free_columns++;
	if (TET_GET_X(tet) > grid_size - 4 + free_columns)
		return (0);
	return (1);
}

int					in_y_bounds(unsigned short tet, unsigned char grid_size)
{
	const unsigned short	border_mask[] = {0x000F, 0x00FF, 0x0FFF};
	int						free_rows;

	free_rows = 0;
	while (free_rows < 3 && ((g_shapes[tet & TET_ID_MASK] & border_mask[free_rows]) == 0))
		free_rows++;
	if (TET_GET_Y(tet) > grid_size - 4 + free_rows)
		return (0);
	return (1);
}

