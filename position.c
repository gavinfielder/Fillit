/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrmart <andrmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:46:43 by andrmart          #+#    #+#             */
/*   Updated: 2019/02/20 16:48:26 by andrmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			pos_of(unsigned short *arr, int n, int pos[2])
{
	pos[0] = TET_GET_X(arr[n]);
	pos[1] = TET_GET_Y(arr[n]);
}

int				*set_ipos(int pos[2], int x, int y)
{
	pos[0] = x;
	pos[1] = y;
	return (pos);
}

int				next_pos(unsigned short *arr, int n, int pos[2],
							unsigned short grid_size)
{
	if (X == -1)
	{
		set_ipos(pos, 0, 0);
		set_pos(&arr[n], X, Y);
		if (!in_x_bounds(arr[n], grid_size) || !in_y_bounds(arr[n], grid_size))
			return (0);
		return (1);
	}
	pos_of(arr, n, pos);
	set_ipos(pos, ++X, Y);
	set_pos(&arr[n], X, Y);
	if (!in_x_bounds(arr[n], grid_size))
	{
		set_ipos(pos, 0, ++Y);
		set_pos(&arr[n], X, Y);
	}
	if (!in_y_bounds(arr[n], grid_size))
		return (0);
	return (1);
}
