/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:02:49 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/16 17:35:55 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "shape.h"
#include "test_functions.h"

int		get_next_tet(int fd)
{
    char buff[21];
    char ret_tet[16];
    int ret;
	int i;

    if ((ret = read(fd, buff, 21)) == 0)
		return (-1);
	else if (ret == -1)
		return (-2);
	else if (ret < 19)
		return (-2);
	i = -1;
    while (++i < ret) //loop through all the read buffer
    {
        if ((i + 1) % 5 == 0) //on i = 4,9,14,19 validate that the character is \n
        {
			if (buff[i] != '\n')
				return (-2);
            continue;
        }
        ret_tet[i - (i + 1) / 5] = buff[i]; //on all other values, copy to ret_tet
    }
	if (ret == 21 && buff[20] != '\n') //validate that there is an extra newline after the tetrimino, if it has not ended
		return (-2);
	//ret_tet now holds the valid number of character in the valid organization
	return (identify(ret_tet));
}

int     main(int ac, char **av)
{
    int fd;
    int n;
	int id;
	unsigned short arr[26];

    if (ac != 2)
        return (0);
    fd = open(av[1], O_RDONLY);
    n = 0;
	printf("62\n");
    while ((id = get_next_tet(fd)) >= 0)
    {
		printf("n=%i\n", n);
        arr[n++] = id;
		if (id < 0)
		{
			if (id == -1)
   	    		printf("unrecognized tetrimino\n");
			else if (id == -2)
				printf("error\n");
		}
		printf("identified shape id=%i\n", id);
		print_shape(g_shapes[id]);
		printf("\n");
    }
	return (0);
}
