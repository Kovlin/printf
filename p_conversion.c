/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:50:27 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:45:24 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_length_output_p(t_format *content, unsigned long nbr)
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
		if (length < ft_len_hexa_p(nbr))
			length = ft_len_hexa_p(nbr);
		if (content->precision > length)
			length = content->precision;
	}
	return (length);
}

void	format_p(unsigned long nbr, t_format *content)
{
	if (content->width < ft_len_hexa_p(nbr))
		if (content->precision <= ft_len_hexa_p(nbr))
			ft_putnbr_hexa_p(nbr, 1);
		else
		{
			ft_x_zero(content->precision - ft_len_hexa_p(nbr));
			ft_putnbr_hexa_p(nbr, 1);
		}
	else
	{
		if (content->precision <= ft_len_hexa_p(nbr))
		{
			ft_x_space(content->width - ft_len_hexa_p(nbr));
			ft_putnbr_hexa_p(nbr, 1);
		}
		else
		{
			ft_x_space(content->width - content->precision);
			ft_x_zero(content->precision - ft_len_hexa_p(nbr));
			ft_putnbr_hexa_p(nbr, 1);
		}
	}
}

void	format_p_left(unsigned long nbr, t_format *content)
{
	if (content->width < ft_len_hexa_p(nbr))
		if (content->precision <= ft_len_hexa_p(nbr))
			ft_putnbr_hexa_p(nbr, 1);
		else
		{
			ft_x_zero(content->precision - ft_len_hexa_p(nbr));
			ft_putnbr_hexa_p(nbr, 1);
		}
	else
	{
		if (content->precision <= ft_len_hexa_p(nbr))
		{
			ft_putnbr_hexa_p(nbr, 1);
			ft_x_space(content->width - ft_len_hexa_p(nbr));
		}
		else
		{
			ft_x_zero(content->precision - ft_len_hexa_p(nbr));
			ft_putnbr_hexa_p(nbr, 1);
			ft_x_space(content->width - content->precision);
		}
	}
}

void	format_p_right(unsigned long nbr, t_format *content)
{
	if (content->width < ft_len_hexa_p(nbr))
		if (content->precision <= ft_len_hexa_p(nbr))
			ft_putnbr_hexa_p(nbr, 1);
		else
		{
			ft_x_zero(content->precision - ft_len_hexa_p(nbr));
			ft_putnbr_hexa_p(nbr, 1);
		}
	else
	{
		if (content->precision <= ft_len_hexa_p(nbr))
		{
			if (content->precision == -1)
				ft_x_zero(content->width - ft_len_hexa_p(nbr));
			else
				ft_x_space(content->width - ft_len_hexa_p(nbr));
			ft_putnbr_hexa_p(nbr, 1);
		}
		else
		{
			ft_x_space(content->width - content->precision);
			ft_x_zero(content->precision - ft_len_hexa_p(nbr));
			ft_putnbr_hexa_p(nbr, 1);
		}
	}
}

void	p_conversion(t_format *content, va_list args)
{
	unsigned long	p;

	p = va_arg(args, unsigned long);
	content->length_output = ft_length_output_p(content, p);
	if (content->flags == 0)
		format_p(p, content);
	else if (content->flags == 1)
		format_p_left(p, content);
	else if (content->flags == 2)
		format_p_right(p, content);
}
