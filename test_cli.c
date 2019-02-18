/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:04:32 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/18 00:25:45 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "tetrimino.h"
#include "output.h"
#include <stdio.h>
#include <stdlib.h>
#include "testing.h"
#include "libft.h"
#include "input.h"
#include "backtracking.h"

static unsigned short	g_tets[26];
static unsigned short	grid_size;
static int	option_silent = 0;

int		main(int argc, char **argv)
{
	int i = 0;

	printf("Welcome to my Fillit command line test utility\n");
	if (argc > 1)
	{
		cmd_reset();
		while (++i < argc)
		{
			if (process_script(argv[i]) == 0)
				return (0);
		}
	}
	else
	{
		cmd_help();
		cmd_reset();
	}
	while (process_stdin());
	return (0);
} 

void	cmd_help()
{
	printf("  AVAILABLE COMMANDS:\n");
	printf("    help / ?			list the available commands\n");
	printf("    list / l			list the current set of tetriminos\n");
	printf("    set [index] [id] [x] [y]	set tet[index] to the specified id and position\n");
	printf("    move [index] [x] [y]	moves the given tetrimino by the requested amount\n");
	printf("    show [index]		print information about the given tetrimino\n");
	printf("    rf [filename]		reads tetriminos from file\n");
	printf("    solve				calls the solving algorithm\n");
	printf("    size [size]			set the grid size\n");
	printf("    print / p			print the grid\n");
	printf("    del [index]			delete the given tetrimino\n");
	printf("    reset			delete all tetriminos and reset grid size to 3\n");
	printf("    run [filename]		run the commands contained in [filename]\n");
	printf("    overlaps [i] [j]		tests whether tetrimino i and j overlap\n");
	printf("    overlaps all		tests every pair of tetriminos for overlap\n");
	printf("    inb [i]			tests whether tetrimino i is in x and y bounds\n");
	printf("    quit / q			exit program\n");
	printf("\n");
	printf("  ADDITIONAL SCRIPT COMMANDS:\n");
	printf("    silent			turns off the 'processing script command' text\n");
	printf("    /				prints an empty line\n");
	printf("    # [comment]			comment\n");
	printf("    @ [comment]			comment and print to stdout\n");
	printf("\n");
}

int		process_cmd(char **words)
{
	if (ft_strnequ(words[0], "help", 4) || ft_strnequ(words[0], "?", 1))
		cmd_help();
	else if (ft_strnequ(words[0], "list", 4) || ft_strnequ(words[0], "l", 1))
		cmd_list();
	else if (ft_strequ(words[0], "set"))
		cmd_set(idx_atoi(words[1]), atoi(words[2]), atoi(words[3]), atoi(words[4]));
	else if (ft_strequ(words[0], "show"))
		cmd_show(idx_atoi(words[1]));
	else if (ft_strequ(words[0], "size"))
		cmd_size(atoi(words[1]));
	else if (ft_strnequ(words[0], "solve", 5))
		cmd_solve();
	else if (ft_strnequ(words[0], "print", 5) || ft_strnequ(words[0], "p", 1))
		cmd_print();
	else if (ft_strequ(words[0], "del"))
		cmd_del(idx_atoi(words[1]));
	else if (ft_strequ(words[0], "rf"))
		cmd_rf(words[1]);
	else if (ft_strnequ(words[0], "reset", 5))
		cmd_reset();
	else if (ft_strequ(words[0], "move"))
		cmd_move(idx_atoi(words[1]), atoi(words[2]), atoi(words[3]));
	else if (ft_strequ(words[0], "overlaps"))
	{
		if (ft_strequ(words[1], "all"))
			cmd_overlaps_all();
		else
			cmd_overlaps(idx_atoi(words[1]), idx_atoi(words[2]));
	}
	else if (ft_strequ(words[0], "run"))
		process_script(words[1]);
	else if (ft_strequ(words[0], "inb"))
		cmd_inb(idx_atoi(words[1]));
	else if (ft_strnequ(words[0], "quit", 4) || ft_strnequ(words[0], "q", 1))
		return (0);
	else if (ft_strnequ(words[0], "/", 1))
		printf("\n");
	else if (ft_strnequ(words[0], "silent", 6))
		option_silent = 1;
	else if (ft_strnequ(words[0], "#", 1))
		; //do nothing
	else if (ft_strnequ(words[0], "@", 1))
	{
		for (int i = 1; words[i] != NULL; i++)
			printf("%s ", words[i]);
		printf("\n");
	}
	else
		printf("Unrecognized command. See 'help' / '?'.\n");
	return (1);
}


int		process_stdin(void)
{
	size_t			buff_size = 32;
	char			*cmd = malloc(buff_size);
	char			**words;
	size_t			j;

	//initialize buffer
	for (int i = 0; i < 32; i++)
		cmd[i] = '\0';
	//get the command line
	printf(" > ");
	getline(&cmd, &buff_size, stdin);
	//make sure there's no trailing newline
	j = 0;
	while (j < buff_size && cmd[j])
		j++;
	if (j > 0)
	{
		if (cmd[j - 1] == '\n')
			cmd[j - 1] = '\0';
	}
	//split the command and process
	words = ft_strsplit(cmd, ' ');
	return (process_cmd(words));
	for (int i = 0; words[i] != NULL; i++)
		free(words[i]);
	free(words);
	free(cmd);
}

int		process_script(char *filename)
{
	size_t			buff_size = 32;
	char			*cmd = malloc(buff_size);
	char			**words;
	int				exit = 0;
	int				error = 0;
	size_t			j;
	FILE 			*fp = fopen(filename, "r");
	if (fp)
	{
		while (getline(&cmd, &buff_size, fp) > 0 && !exit)
		{
			//make sure there's no trailing newline
			j = 0;
			while (j < buff_size && cmd[j])
				j++;
			if (j > 0)
			{
				if (cmd[j - 1] == '\n')
					cmd[j - 1] = '\0';
			}
			if (!option_silent) printf("Processing script command:   %s\n", cmd);
			//split the command and process
			words = ft_strsplit(cmd, ' ');
			if (process_cmd(words) == 0)
				exit = 1;
			for (int i = 0; words[i] != NULL; i++)
				free(words[i]);
			free(words);
		}
		fclose(fp);
		fp = NULL;
	}
	else
	{
		printf("Error opening script.\n");
		error = 1;
	}
	free(cmd);
	if (exit)
		return (0);
	else
	{
		if (!error)
			printf("script finished execution: %s\n", filename);
		return (1);
	}
}

//atoi, but also converts a/A to 0, b/B to 1, etc.
int		idx_atoi(char *index_str)
{
	if (*index_str >= 'A' && *index_str <= 'Z')
		return (*index_str - 'A');
	if (*index_str >= 'a' && *index_str <= 'z')
		return (*index_str - 'a');
	return (atoi(index_str));
}

void	cmd_rf(char *filename)
{
	if (read_file(g_tets, filename) < 0)
		printf("An error occurred while attempting to read the requested file.\n");
	else
		printf("File reading completed.\n");
}

void	cmd_solve(void)
{
	printf("Solving is currently disabled.\n");
	return ;

	unsigned short result = backtracking(g_tets, 0, init_pos(), grid_size);
	if (result == 1)
		printf("Success\n");
	else
		printf("Error while solving.\n");
}

void	cmd_move(int index, int x, int y)
{
	if (index < 0 || index > 25)
	{
		printf("usage: move [index] [x] [y]\n");
		return ;
	}
	int prev_x = TET_GET_X(g_tets[index]);
	int prev_y = TET_GET_Y(g_tets[index]);

	if (prev_x + x < 0 || prev_y + y < 0)
	{
		printf("Cannot move to a negative position.\n");
		return ;
	}
	x += prev_x;
	y += prev_y;
	set_pos(&g_tets[index], (unsigned short)x, (unsigned short)y);
	printf("tet %i moved to {x=%i, y=%i}\n", index, x, y);
}

void	cmd_inb(int i)
{
	if (i < 0 || i >= get_number_of_tets())
	{
		printf("usage: inb [i]\n");
		return ;
	}
	if (in_x_bounds(g_tets[i], grid_size))
		printf("tet %i is in X bounds of the grid.\n", i);
	else
		printf("tet %i is not in X bounds of the grid.\n", i);
	if (in_y_bounds(g_tets[i], grid_size))
		printf("tet %i is in Y bounds of the grid.\n", i);
	else
		printf("tet %i is not in Y bounds of the grid.\n", i);
}

void	cmd_overlaps_all(void)
{
	int n = get_number_of_tets();
	int i = 0;
	int j = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			cmd_overlaps(i, j);
			j++;
		}
		i++;
	}
}

void	cmd_overlaps(int i, int j)
{
	if (i < 0 || j < 0 || i > 25 || j > 25)
	{
		printf("usage: overlaps [i] [j]\n");
		return ;
	}
	if (overlaps(g_tets[i], g_tets[j]))
		printf("Tetriminos %c and %c overlap.\n", 'A' + i, 'A' + j);
	else
		printf("Tetriminos %c and %c do not overlap.\n", 'A' + i, 'A' + j);
}

void	cmd_del(int index)
{
	if (index < 0 || index > 25)
	{
		printf("usage: del [i]\n");
		return ;
	}
	g_tets[index] = 0;
	printf("tet %i removed.\n", index);
}

void	cmd_reset(void)
{
	for (int i = 0; i < 26; i++)
		g_tets[i] = 0;
	grid_size = 3;
	printf("tets and grid reset to default values.\n");
}

void	cmd_list()
{
	int n = get_number_of_tets();
	if (n == 0)
		printf("There are currently no tets defined.\n");
	for (int i = 0; i < n; i++)
	{
		if (g_tets[i] == 0)
			printf("    %i\t: EMPTY\n", i);
		else
			print_tet_listing(i);
	}
}

void	cmd_set(int index, int id, int x, int y)
{
	if (index < 0 || index > 25 || x < 0 || y < 0 || id < 0 || id > 18)
	{
		printf("usage: set [index] [id] [x] [y]\n");
		return ;
	}
	g_tets[index] = id;
	set_pos(&g_tets[index], x, y);
	g_tets[index] |= TET_ACTIVE_BIT;
	printf("tet set:\n");
	print_tet_listing(index);
	if (!in_x_bounds(g_tets[index], grid_size))
		printf("WARNING: tet %i is not in the X bounds of the current grid.\n", index);
	if (!in_y_bounds(g_tets[index], grid_size))
		printf("WARNING: tet %i is not in the Y bounds of the current grid.\n", index);
}

void	cmd_show(int i)
{
	if (i < 0 || i > 25)
	{
		printf("usage: show [index]\n");
		return ;
	}
	print_shape(g_shapes[g_tets[i] & TET_ID_MASK]);
	print_tet_listing(i);
}

void	print_tet_listing(int i)
{
	if (g_tets[i] == 0)
		printf("    %i\t: EMPTY\n", i);
	else
		printf("    %i (%c)\t: id=%i, pos: {x=%i, y=%i}\n", i, 'A' + i,
					g_tets[i] & TET_ID_MASK, TET_GET_X(g_tets[i]), TET_GET_Y(g_tets[i]));
}

void	cmd_size(int size)
{
	if (size < 3)
	{
		printf("Grid size cannot be less than 3.\n");
		return ;
	}
	if (size > 32)
	{
		printf("Grid size cannot be greater than 32.\n");
		return ;
	}
	grid_size = size;
	printf("Grid size set to %ix%i.\n", size, size);
	//check whether all the tets are in the current grid
	int good = 1;
	int n = get_number_of_tets();
	for (int i = 0; good && i < n; i++)
	{
		good &= (in_x_bounds(g_tets[i], grid_size) && in_y_bounds(g_tets[i], grid_size));
	}
	if (!good)
		printf("WARNING: Not all tets fit in the newly resized grid.\n");
}

void	cmd_print()
{
	print_square(g_tets, get_number_of_tets(), grid_size);
}

int		get_number_of_tets()
{
	int n = 0;
	while (g_tets[n] != 0)
		n++;
	return (n);
}
