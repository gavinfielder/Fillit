/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrmart <andrmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:02:49 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/20 20:57:59 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>

int		get_next_tet(int fd, int *id)
{
	char	buff[21];
	char	converted_input[16];
	int		status;
	int		read_ret;

	status = INPUT_OK;
	ft_bzero(buff, 21);
	read_ret = read(fd, buff, 21);
	if (read_ret < 20)
		return (INPUT_ERR);
	status = convert_input(buff, converted_input);
	if (status == INPUT_ERR)
		return (INPUT_ERR);
	*id = identify(converted_input);
	if (*id < 0)
		return (INPUT_ERR);
	return (status);
}

int		convert_input(char *buff, char *ret_tet)
{
	int	i;

	ft_bzero(ret_tet, 16);
	i = -1;
	while (++i < 20)
	{
		if ((i + 1) % 5 == 0)
		{
			if (buff[i] != '\n')
				return (INPUT_ERR);
			continue;
		}
		ret_tet[i - (i + 1) / 5] = buff[i];
	}
	if (buff[20] == '\0')
		return (INPUT_EOF);
	if (buff[20] == '\n')
		return (INPUT_OK);
	return (INPUT_ERR);
}

int		read_file(unsigned short *tets, char *filename)
{
	int fd;
	int n;
	int id;
	int ret;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (INPUT_ERR);
	id = -1;
	ret = INPUT_OK;
	n = 0;
	while (1)
	{
		ret = get_next_tet(fd, &id);
		tets[n] = (unsigned short)id;
		tets[n] |= TET_ACTIVE_BIT;
		n++;
		if (ret != INPUT_OK)
			break ;
		if (n == 26)
			return (INPUT_ERR);
	}
	close(fd);
	if (ret == INPUT_EOF)
		return (INPUT_OK);
	return (INPUT_ERR);
}
