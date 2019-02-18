/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:02:49 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/17 22:37:34 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "shape.h"
#include "testing.h"

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

int		read_file(unsigned short *tets, char *filename)
{
	int fd;
    int n;
	int id;

	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		n = 0;
		while ((id = get_next_tet(fd)) >= 0)
		{
			if (id < 0)
			{
				if (id == -1)
				{
					printf("unrecognized tetrimino\n");
					return (-1);
				}
				else if (id == -2)
				{
					printf("error\n");
					return (-2);
				}
			}
			else
			{
				tets[n] = (unsigned short)id;
				tets[n] |= TET_ACTIVE_BIT;
				printf("identified shape id=%i\n", id);
				n++;
			}
		}
		close(fd);
	}
	return (1);
}
