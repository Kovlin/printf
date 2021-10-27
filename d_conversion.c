/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:53:16 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:23:20 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_len_neg(unsigned int nbr)
{
	int i;

	i = 0;
	while (nbr / 10 != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i + 2);
}

int		length_output_neg(t_format *content, unsigned int number)
{
	int length;

	length = ft_len_neg(number);
	if (content->width > length)
		length = content->width;
	if (content->precision > length)
		length = content->precision;
	if (content->precision == length)
		length++;
	return (length);
}

void	d_conversion(t_format *content, va_list args)
{
	int nbr;

	nbr = va_arg(args, int);
	if (nbr >= 0)
	{
		content->length_output = length_output_u(content, (unsigned int)nbr);
		format_pos_nbr(content, (unsigned int)nbr);
	}
	else
	{
		nbr *= -1;
		content->length_output = length_output_neg(content, (unsigned int)nbr);
		format_neg_nbr(content, (unsigned int)nbr);
	}
}
