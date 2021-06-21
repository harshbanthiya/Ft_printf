/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:43:39 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/21 15:46:48 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	struct
	{
		unsigned short	show_sign;
		unsigned short	left_justify;
		unsigned short	zero_pad;
		unsigned short	alternate_output;
		unsigned short	initial_space;
		unsigned short	uppercase;
	}s_flags;
	int		width;
	int		precision;
	char	length_modifier;
	char	type_specifier;
	enum 	{ OUTPUT_NONE, OUTPUT_STDOUT }e_mode;
}				t_data;

#endif
