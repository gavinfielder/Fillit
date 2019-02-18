/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:44:56 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/17 17:05:26 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "tetrimino.h"
#include "output.h"
#include <stdio.h>
#include <stdlib.h>
#include "testing.h"
#include "libft.h"

void	print_tet_raw(char *str)
{
	printf("%s\n", str);
}

void	print_shape(unsigned short shape)
{
	unsigned int mask = 0x8000;
	unsigned int i = 0;
	while (mask)
	{
		if (shape & mask)
			printf("#");
		else
			printf(".");
		i++;
		if (i % 4 == 0)
			printf("\n");
		mask >>= 1;
	}
}

void	test_identify(char *data)
{
	printf("Testing: \"%s\"\n", data);
	int id = identify(data);
	printf("id = %i\n", id);
}



