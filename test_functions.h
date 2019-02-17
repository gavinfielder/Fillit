/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:39:07 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/16 15:42:35 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FUNCTIONS_H
# define TEST_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void	print_tet_raw(char *str);
void	print_shape(unsigned short shape);
void	test_identify(char *data);
void	run_identity_tests();

#endif
