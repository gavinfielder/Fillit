/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 23:39:20 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/18 00:19:13 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKING_H
# define BACKTRACKING_H

# define X pos[0]
# define Y pos[1]

int                 *init_pos(void);
int                 *pos(int pos[2], unsigned short grid_size);
unsigned short      validate(unsigned short arr[26], int n/*, int pos[2]*/);
unsigned short      backtracking(unsigned short arr[26], int n, int pos[2], unsigned short grid_size);

#endif
