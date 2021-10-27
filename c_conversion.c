/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:23:30 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:20:11 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		length_output_c(t_format *content)
{
	if (content->width > 1)
		return (content->width);
	return (1);
}

void	format_c(t_format *content, int c)
{
	if (content->flags != 1)
	{
		if (content->width > 1)
			ft_x_space(content->width - 1);
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_putchar_fd(c, 1);
		if (content->width > 1)
			ft_x_space(content->width - 1);
	}
}

void	c_conversion(t_format *content, va_list args)
{
	int c;

	c = va_arg(args, int);
	content->length_output = length_output_c(content);
	format_c(content, c);
}
