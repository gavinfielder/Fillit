/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:55:25 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/17 17:52:12 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

# define TET_ACTIVE_BIT 0x8000
# define TET_ID_MASK 0x001F		//0000.0000.0001.1111
# define TET_X_MASK 0x03E0 		//0000.0011.1110.0000
# define TET_Y_MASK 0x7C00		//0111.1100.0000.0000
# define TET_X_SHFT 5
# define TET_Y_SHFT 10
# define TET_GET_X(T) ((T & TET_X_MASK) >> TET_X_SHFT)
# define TET_GET_Y(T) ((T & TET_Y_MASK) >> TET_Y_SHFT)

void				set_pos(unsigned short *tet,
						unsigned short x, unsigned short y);
int					in_x_bounds(unsigned short tet, unsigned char grid_size);
int					in_y_bounds(unsigned short tet, unsigned char grid_size);

#endif
