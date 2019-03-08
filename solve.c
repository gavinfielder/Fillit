/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:50:05 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/21 18:07:27 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short	validate(unsigned short *arr, int n)
{
	int				i;

	i = -1;
	while (++i < n)
	{
		if (overlaps(arr[i], arr[n]))
			return (0);
	}
	return (1);
}

static unsigned short	try_grid_size(unsigned short *arr, int n, int pos[2],
								unsigned short grid_size)
{
	if (!arr[n])
		return (1);
	while (next_pos(arr, n, pos, grid_size))
	{
		if (validate(arr, n))
		{
			if (try_grid_size(arr, n + 1, set_ipos(pos, -1, -1), grid_size))
				return (1);
		}
	}
	return (0);
}

unsigned char			solve(unsigned short arr[26],
							unsigned short grid_size)
{
	int pos[2];

	if (grid_size > 32)
		return (0);
	if (try_grid_size(arr, 0, set_ipos(pos, -1, -1), grid_size))
		return (grid_size);
	return (solve(arr, grid_size + 1));
}
