/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrmart <andrmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:25:18 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/21 14:00:06 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stddef.h>
# include "libft.h"

/*
** ------------------------ Constant Global Shape Data -------------------------
**                           values defined in shape.c
*/

extern const unsigned short	g_shapes[];

/*
** -------------------------------- Input --------------------------------------
**                                 input.c
*/

# define INPUT_EOF -1
# define INPUT_ERR -2
# define INPUT_OK 1

int							get_next_tet(int fd, int *id);
int							convert_input(char *buff, char *ret_tet);
int							read_file(unsigned short *tets, char *filename);

/*
** ------------------------- Shape data manipulation ---------------------------
**                                  shape.c
*/

# define SHAPE_ROW1 0xF000
# define SHAPE_COL1 0x8888
# define SHAPE_ERROR 0xFFFF
# define INVALID_SHAPE -2

unsigned short				overlaps(unsigned short tet1,
								unsigned short tet2);
int							identify(char *data);

/*
** ---------------------------- Solution Finding -------------------------------
**                         backtracking.c, position.c
*/

# define X pos[0]
# define Y pos[1]

void						pos_of(unsigned short *arr, int n, int pos[2]);
int							next_pos(unsigned short *arr, int n, int pos[2],
								unsigned short grid_size);
unsigned char				solve(unsigned short *arr,
								unsigned short grid_size);
int							*set_ipos(int pos[2], int x, int y);

/*
** ----------------------- Manipulating Tetrimino data -------------------------
**                               see tetrimino.c
*/

# define TET_ACTIVE_BIT 0x8000
# define TET_ID_MASK 0x001F
# define TET_X_MASK 0x03E0
# define TET_Y_MASK 0x7C00
# define TET_POS_MASK 0x7FE0
# define TET_X_SHFT 5
# define TET_Y_SHFT 10
# define TET_GET_X(T) ((T & TET_X_MASK) >> TET_X_SHFT)
# define TET_GET_Y(T) ((T & TET_Y_MASK) >> TET_Y_SHFT)

void						set_pos(unsigned short *tet, unsigned short x,
								unsigned short y);
int							in_x_bounds(unsigned short tet,
								unsigned char grid_size);
int							in_y_bounds(unsigned short tet,
								unsigned char grid_size);

/*
** -------------------------------- Output -------------------------------------
**                                 output.c
*/

# define DATA_SIZE ((square_size + 1) * square_size)

void						write_tet_to_square(unsigned short tet,
								unsigned char square_size, char *square,
								char tet_letter);
void						print_square(unsigned short *tets,
								unsigned char num_tets,
								unsigned char square_size);

#endif
