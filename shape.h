/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:49:59 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/16 17:08:18 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# define TET_ID_MASK 0x001F
# define TET_X_MASK 0x03E0
# define TET_Y_MASK 0xEC00
# define TET_X_SHFT 5
# define TET_Y_SHFT 10
# define TET_GET_X(T) ((T & TET_X_MASK) >> TET_X_SHFT)
# define TET_GET_Y(T) ((T & TET_Y_MASK) >> TET_Y_SHFT)
# define SHAPE_ROW1 0xF000
# define SHAPE_COL1 0x8888
# define SHAPE_ERROR 0xFFFF

extern const unsigned short	g_shapes[];

unsigned short		horiz_shift(unsigned short shape, unsigned short x);
unsigned short		vert_shift(unsigned short shape, unsigned short y);
unsigned short		overlaps(unsigned short tet1, unsigned short tet2);
int					identify(char *data);
unsigned short		str_to_shape(char *data);

#endif
