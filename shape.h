/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:49:59 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/17 17:49:37 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

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
