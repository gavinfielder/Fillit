/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrmart <andrmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 22:18:18 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/21 17:49:35 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

int		error(void)
{
	write(1, "error\n", 6);
	return (0);
}

int		initial_size(int num_tets)
{
	int size;

	size = 2;
	while (size * size < num_tets * 4)
		size++;
	return (size);
}

int		usage(void)
{
	write(1, "usage: ./fillit tet_file.txt\n", 29);
	return (0);
}

int		get_number_of_tets(unsigned short *tets)
{
	int n;

	n = 0;
	while (tets[n] != 0)
		n++;
	return (n);
}

int		main(int ac, char **av)
{
	unsigned char	grid_size;
	unsigned short	tets[26];
	int				number_of_tets;

	ft_bzero(tets, 52);
	if (ac != 2)
		return (usage());
	if (read_file(tets, av[1]) < 0)
		return (error());
	number_of_tets = get_number_of_tets(tets);
	if (number_of_tets == 0)
		return (error());
	grid_size = solve(tets, initial_size(number_of_tets));
	if (!(grid_size))
		return (error());
	print_square(tets, get_number_of_tets(tets), grid_size);
	return (0);
}
