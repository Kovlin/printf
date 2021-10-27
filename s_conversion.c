/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:44:28 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:48:19 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		length_output_s(t_format *content, char *s)
{
	int length;

	if (content->precision > (int)ft_strlen(s) || content->precision == -1)
		length = (int)ft_strlen(s);
	else
		length = content->precision;
	if (content->width > length)
		length = content->width;
	return (length);
}

void	print_n_c(char *s, int i)
{
	while (i > 0)
	{
		ft_putchar_fd(*s, 1);
		s++;
		i--;
	}
}

void	format_s_left(t_format *content, char *s, int to_print)
{
	print_n_c(s, to_print);
	ft_x_space(content->width - to_print);
}

void	format_s(t_format *content, char *s)
{
	int to_print;

	if (content->precision > (int)ft_strlen(s) || content->precision == -1)
		to_print = (int)ft_strlen(s);
	else
		to_print = content->precision;
	if (content->flags == 0)
	{
		if (content->width > to_print)
			ft_x_space(content->width - to_print);
		print_n_c(s, to_print);
	}
	else if (content->flags == 1)
		format_s_left(content, s, to_print);
}

void	s_conversion(t_format *content, va_list args)
{
	char *s;

	s = va_arg(args, char*);
	if (!s)
		s = "(null)";
	content->length_output = length_output_s(content, s);
	format_s(content, s);
}
