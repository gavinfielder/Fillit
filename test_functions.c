/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:44:56 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/16 17:30:21 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include <stdio.h>
#include <stdlib.h>

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



/*

....
..##
..#.
..#.



*/

void	run_identity_tests()
{
	test_identify(".##.##..........");
	test_identify("..##..#...#.....");
	test_identify("......##..#...#.");

}
/*
int		main(int argc, char **argv)
{
	int id = -1;
	int x = 0;
	int y = 0;

	run_identity_tests();

	/ *
	if (argc > 3)
	{
		id = atoi(argv[1]);
		x = atoi(argv[2]);
		y = atoi(argv[3]);
		if (id > 18 || id < 0)
			return (0);
		printf("Printing shape #%i, shifted by x=%i, y=%i.\n", id, x, y);
		print_shape(vert_shift(horiz_shift(g_shapes[id], x), y));
	}
	* /
	return (0);
} */



