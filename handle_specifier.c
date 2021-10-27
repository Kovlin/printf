/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:39:35 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:37:06 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_spec(char *format, int *index, t_format *content, va_list args)
{
	if (format[*index] == '%')
		percent_conversion(content);
	if (format[*index] == 'c')
		c_conversion(content, args);
	if (format[*index] == 's')
		s_conversion(content, args);
	if (format[*index] == 'p')
		p_conversion(content, args);
	if (format[*index] == 'x')
		x_conversion(content, args, 0);
	if (format[*index] == 'X')
		x_conversion(content, args, 1);
	if (format[*index] == 'u')
		u_conversion(content, args);
	if (format[*index] == 'd' || format[*index] == 'i')
		d_conversion(content, args);
	(*index)++;
}
