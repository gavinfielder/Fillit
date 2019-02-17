/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:39:07 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/17 15:02:09 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FUNCTIONS_H
# define TEST_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


void	cmd_help(void);
int		process_cmd(void);
void	cmd_overlaps(int i, int j);
int		get_number_of_tets(void);
void	cmd_del(int index);
void	cmd_reset(void);
void	cmd_list(void);
void	cmd_set(int index, int id, int x, int y);
void	cmd_show(int index);
void	cmd_size(int size);
void	cmd_print(void);
void	print_tet_raw(char *str);
void	print_shape(unsigned short shape);
void	test_identify(char *data);



#endif
