/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_neg_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:48:29 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 18:14:08 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_neg(unsigned int nbr, t_format *content)
{
	if (content->width < ft_len_neg(nbr))
	{
		ft_putchar_fd('-', 1);
		if (content->precision >= ft_len_neg(nbr))
			ft_x_zero(content->precision - ft_len_neg(nbr) + 1);
		ft_putnbr_unsigned_fd(nbr, 1);
	}
	else
	{
		if (content->precision < ft_len_neg(nbr))
		{
			ft_x_space(content->width - ft_len_neg(nbr));
			ft_putchar_fd('-', 1);
			ft_putnbr_unsigned_fd(nbr, 1);
		}
		else
		{
			ft_x_space(content->width - content->precision - 1);
			ft_putchar_fd('-', 1);
			ft_x_zero(content->precision - ft_len_neg(nbr) + 1);
			ft_putnbr_unsigned_fd(nbr, 1);
		}
	}
}

void	format_neg_left(unsigned int nbr, t_format *content)
{
	if (content->width < ft_len_neg(nbr))
	{
		ft_putchar_fd('-', 1);
		if (content->precision >= ft_len_neg(nbr))
			ft_x_zero(content->precision - ft_len_neg(nbr) + 1);
		ft_putnbr_unsigned_fd(nbr, 1);
	}
	else
	{
		if (content->precision < ft_len_neg(nbr))
		{
			ft_putchar_fd('-', 1);
			ft_putnbr_unsigned_fd(nbr, 1);
			ft_x_space(content->width - ft_len_neg(nbr));
		}
		else
		{
			ft_putchar_fd('-', 1);
			ft_x_zero(content->precision - ft_len_neg(nbr) + 1);
			ft_putnbr_unsigned_fd(nbr, 1);
			ft_x_space(content->width - content->precision - 1);
		}
	}
}

void	format_neg_right_next(unsigned int nbr, t_format *content)
{
	if (content->precision < ft_len_neg(nbr))
	{
		if (content->precision == -1)
		{
			ft_putchar_fd('-', 1);
			ft_x_zero(content->width - ft_len_neg(nbr));
		}
		else
		{
			ft_x_space(content->width - ft_len_neg(nbr));
			ft_putchar_fd('-', 1);
		}
		ft_putnbr_unsigned_fd(nbr, 1);
	}
	else
	{
		ft_x_space(content->width - content->precision - 1);
		ft_putchar_fd('-', 1);
		ft_x_zero(content->precision - ft_len_neg(nbr) + 1);
		ft_putnbr_unsigned_fd(nbr, 1);
	}
}

void	format_neg_right(unsigned int nbr, t_format *content)
{
	if (content->width < ft_len_neg(nbr))
	{
		ft_putchar_fd('-', 1);
		if (content->precision >= ft_len_neg(nbr))
			ft_x_zero(content->precision - ft_len_neg(nbr) + 1);
		ft_putnbr_unsigned_fd(nbr, 1);
	}
	else
		format_neg_right_next(nbr, content);
}

void	format_neg_nbr(t_format *content, unsigned int number)
{
	if (content->flags == 0)
		format_neg(number, content);
	else if (content->flags == 1)
		format_neg_left(number, content);
	else
		format_neg_right(number, content);
}
