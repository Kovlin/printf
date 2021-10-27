/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pos_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:52:56 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:28:12 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_u(unsigned int nbr, t_format *content)
{
	if (content->width < ft_len_u(nbr))
		if (content->precision <= ft_len_u(nbr))
			ft_putnbr_unsigned_fd(nbr, 1);
		else
		{
			ft_x_zero(content->precision - ft_len_u(nbr));
			ft_putnbr_unsigned_fd(nbr, 1);
		}
	else
	{
		if (content->precision <= ft_len_u(nbr))
		{
			ft_x_space(content->width - ft_len_u(nbr));
			ft_putnbr_unsigned_fd(nbr, 1);
		}
		else
		{
			ft_x_space(content->width - content->precision);
			ft_x_zero(content->precision - ft_len_u(nbr));
			ft_putnbr_unsigned_fd(nbr, 1);
		}
	}
}

void	format_u_left(unsigned int nbr, t_format *content)
{
	if (content->width < ft_len_u(nbr))
		if (content->precision <= ft_len_u(nbr))
			ft_putnbr_unsigned_fd(nbr, 1);
		else
		{
			ft_x_zero(content->precision - ft_len_u(nbr));
			ft_putnbr_unsigned_fd(nbr, 1);
		}
	else
	{
		if (content->precision <= ft_len_u(nbr))
		{
			ft_putnbr_unsigned_fd(nbr, 1);
			ft_x_space(content->width - ft_len_u(nbr));
		}
		else
		{
			ft_x_zero(content->precision - ft_len_u(nbr));
			ft_putnbr_unsigned_fd(nbr, 1);
			ft_x_space(content->width - content->precision);
		}
	}
}

void	format_u_right(unsigned int nbr, t_format *content)
{
	if (content->width < ft_len_u(nbr))
		if (content->precision <= ft_len_u(nbr))
			ft_putnbr_unsigned_fd(nbr, 1);
		else
		{
			ft_x_zero(content->precision - ft_len_u(nbr));
			ft_putnbr_unsigned_fd(nbr, 1);
		}
	else
	{
		if (content->precision <= ft_len_u(nbr))
		{
			if (content->precision == -1)
				ft_x_zero(content->width - ft_len_u(nbr));
			else
				ft_x_space(content->width - ft_len_u(nbr));
			ft_putnbr_unsigned_fd(nbr, 1);
		}
		else
		{
			ft_x_space(content->width - content->precision);
			ft_x_zero(content->precision - ft_len_u(nbr));
			ft_putnbr_unsigned_fd(nbr, 1);
		}
	}
}

void	format_pos_nbr(t_format *content, unsigned int number)
{
	if (number == 0 && content->precision == 0)
	{
		if (content->width > 0)
			ft_x_space(content->width);
		else
			content->length_output--;
		return ;
	}
	else if (content->flags == 0)
		format_u(number, content);
	else if (content->flags == 1)
		format_u_left(number, content);
	else
		format_u_right(number, content);
}
