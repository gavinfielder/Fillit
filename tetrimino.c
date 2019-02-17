/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:54:44 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/16 15:55:03 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"

void				set_pos(unsigned short tet,
						unsigned short x, unsigned short y)
{
	tet &= ~TET_X_MASK;
	tet &= ~TET_Y_MASK;
	tet |= (x << TET_X_SHFT);
	tet |= (y << TET_Y_SHFT);
}
