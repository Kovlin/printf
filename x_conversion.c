/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:07:04 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:51:16 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_length_output_x(t_format *content, unsigned int nbr)
{
	int length;

	if (content->precision == 0 && nbr == 0)
	{
		length = 0;
		if (content->width > length)
			length = content->width;
	}
	else
	{
		length = content->width;
		if (length < ft_len_hexa(nbr))
			length = ft_len_hexa(nbr);
		if (content->precision > length)
			length = content->precision;
	}
	return (length);
}

void	format_x(int nbr, int check, t_format *content)
{
	if (content->width < ft_len_hexa(nbr))
		if (content->precision <= ft_len_hexa(nbr))
			ft_putnbr_hexa(nbr, check);
		else
		{
			ft_x_zero(content->precision - ft_len_hexa(nbr));
			ft_putnbr_hexa(nbr, check);
		}
	else
	{
		if (content->precision <= ft_len_hexa(nbr))
		{
			ft_x_space(content->width - ft_len_hexa(nbr));
			ft_putnbr_hexa(nbr, check);
		}
		else
		{
			ft_x_space(content->width - content->precision);
			ft_x_zero(content->precision - ft_len_hexa(nbr));
			ft_putnbr_hexa(nbr, check);
		}
	}
}

void	format_x_left(int nbr, int check, t_format *content)
{
	if (content->width < ft_len_hexa(nbr))
		if (content->precision <= ft_len_hexa(nbr))
			ft_putnbr_hexa(nbr, check);
		else
		{
			ft_x_zero(content->precision - ft_len_hexa(nbr));
			ft_putnbr_hexa(nbr, check);
		}
	else
	{
		if (content->precision <= ft_len_hexa(nbr))
		{
			ft_putnbr_hexa(nbr, check);
			ft_x_space(content->width - ft_len_hexa(nbr));
		}
		else
		{
			ft_x_zero(content->precision - ft_len_hexa(nbr));
			ft_putnbr_hexa(nbr, check);
			ft_x_space(content->width - content->precision);
		}
	}
}

void	format_x_right(int nbr, int check, t_format *content)
{
	if (content->width < ft_len_hexa(nbr))
		if (content->precision <= ft_len_hexa(nbr))
			ft_putnbr_hexa(nbr, check);
		else
		{
			ft_x_zero(content->precision - ft_len_hexa(nbr));
			ft_putnbr_hexa(nbr, check);
		}
	else
	{
		if (content->precision <= ft_len_hexa(nbr))
		{
			if (content->precision == -1)
				ft_x_zero(content->width - ft_len_hexa(nbr));
			else
				ft_x_space(content->width - ft_len_hexa(nbr));
			ft_putnbr_hexa(nbr, check);
		}
		else
		{
			ft_x_space(content->width - content->precision);
			ft_x_zero(content->precision - ft_len_hexa(nbr));
			ft_putnbr_hexa(nbr, check);
		}
	}
}

void	x_conversion(t_format *content, va_list args, int check)
{
	int nbr;

	nbr = va_arg(args, unsigned int);
	content->length_output = ft_length_output_x(content, nbr);
	if (nbr == 0 && content->precision == 0)
	{
		ft_x_space(content->width);
	}
	else if (content->flags == 0)
		format_x(nbr, check, content);
	else if (content->flags == 1)
		format_x_left(nbr, check, content);
	else if (content->flags == 2)
		format_x_right(nbr, check, content);
}
