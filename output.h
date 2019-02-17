/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:03:24 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/17 15:00:01 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

void	write_tet_to_square(unsigned short tet, unsigned char square_size,
			char *square, char tet_letter);
void	print_square(unsigned short *tets, unsigned char num_tets,
			unsigned char square_size);

#endif
