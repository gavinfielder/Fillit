/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:44:56 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/17 15:25:33 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "tetrimino.h"
#include "output.h"
#include <stdio.h>
#include <stdlib.h>
#include "test_functions.h"
#include "libft.h"


static unsigned short	g_tets[26];
static unsigned short	grid_size;


int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	cmd_reset();
	printf("Welcome to my Fillit command line test utility\n");
	cmd_help();
	while (process_cmd());
	return (0);
} 

void	cmd_help()
{
	printf("  AVAILABLE COMMANDS:\n");
	printf("    help / ?					list the available commands\n");
	printf("    list / l					list the current set of tetriminos\n");
	printf("    set [index] [id] [x] [y]	set tet[index] to the specified id and position\n");
	printf("    show [index]				print information about the given tetrimino\n");
	printf("    size [size]					set the grid size\n");
	printf("    print / p					print the grid\n");
	printf("    del [index]					delete the given tetrimino\n");
	printf("    reset						delete all tetriminos and reset grid size to 3\n");
	printf("    overlaps [i] [j]			tests whether tetrimino i and j overlap\n");
	printf("    quit / q					exit program\n");
}

int		process_cmd(void)
{
	size_t			buff_size = 32;
	char			*cmd = malloc(buff_size);
	char			**words;

	getline(&cmd, &buff_size, stdin);
	words = ft_strsplit(cmd, ' ');

	if (ft_strnequ(words[0], "help", 4) || ft_strnequ(words[0], "?", 1))
		cmd_help();
	else if (ft_strnequ(words[0], "list", 4) || ft_strnequ(words[0], "l", 1))
		cmd_list();
	else if (ft_strequ(words[0], "set"))
		cmd_set(atoi(words[1]), atoi(words[2]), atoi(words[3]), atoi(words[4]));
	else if (ft_strequ(words[0], "show"))
		cmd_show(atoi(words[1]));
	else if (ft_strequ(words[0], "size"))
		cmd_size(atoi(words[1]));
	else if (ft_strnequ(words[0], "print", 5) || ft_strnequ(words[0], "p", 1))
		cmd_print();
	else if (ft_strequ(words[0], "del"))
		cmd_del(atoi(words[1]));
	else if (ft_strnequ(words[0], "reset", 5))
		cmd_reset();
	else if (ft_strequ(words[0], "overlaps"))
		cmd_overlaps(atoi(words[1]), atoi(words[2]));
	else if (ft_strnequ(words[0], "quit", 4) || ft_strnequ(words[0], "q", 1))
		return (0);
	else
		printf("Unrecognized command. See 'help' / '?'.\n");
	for (int i = 0; words[i] != NULL; i++)
		free(words[i]);
	free(words);
	free(cmd);
	return (1);
}

void	cmd_overlaps(int i, int j)
{
	if (overlaps(g_tets[i], g_tets[j]))
		printf("Tetriminos %i and %i overlap.\n", i, j);
	else
		printf("Tetriminos %i and %i do not overlap.\n", i, j);
}

int		get_number_of_tets()
{
	int n = 0;
	while (g_tets[n] != 0)
		n++;
	return (n);
}

void	cmd_del(int index)
{
	g_tets[index] = 0;
}

void	cmd_reset(void)
{
	for (int i = 0; i < 26; i++)
		g_tets[i] = 0;
	grid_size = 3;
}


void	cmd_list()
{
	int n = get_number_of_tets();
	for (int i = 0; i < n; i++)
	{
		if (g_tets[i] == 0)
			printf("    %i\t: EMPTY\n", i);
		else
			printf("    %i\t: id=%i, pos: {x=%i, y=%i}\n", i,
					g_tets[i] & TET_ID_MASK, TET_GET_X(g_tets[i]), TET_GET_Y(g_tets[i]));
	}
}

void	cmd_set(int index, int id, int x, int y)
{
	g_tets[index] = id;
	set_pos(&g_tets[index], x, y);
}

void	cmd_show(int i)
{
	print_shape(g_shapes[g_tets[i] & TET_ID_MASK]);
	printf("    %i\t: id=%i, pos: {x=%i, y=%i}\n", i,
					g_tets[i] & TET_ID_MASK, TET_GET_X(g_tets[i]), TET_GET_Y(g_tets[i]));

}

void	cmd_size(int size)
{
	grid_size = size;
}

void	cmd_print()
{
	print_square(g_tets, get_number_of_tets(), grid_size);
}

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



