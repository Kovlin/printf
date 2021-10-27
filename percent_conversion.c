/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:57:45 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:46:39 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		length_output_percent(t_format *content)
{
	int length;

	length = 1;
	if (content->width > length)
		length = content->width;
	return (length);
}

void	percent_conversion(t_format *content)
{
	content->length_output = length_output_percent(content);
	if (content->flags == 0)
	{
		ft_x_space(content->width - 1);
		ft_putchar_fd('%', 1);
	}
	else if (content->flags == 1)
	{
		ft_putchar_fd('%', 1);
		ft_x_space(content->width - 1);
	}
	else
	{
		ft_x_zero(content->width - 1);
		ft_putchar_fd('%', 1);
	}
}
