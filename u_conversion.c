/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:10:30 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:49:50 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_len_u(unsigned int nbr)
{
	int i;

	i = 0;
	while (nbr / 10 != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i + 1);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if ((n / 10) != 0)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

int		length_output_u(t_format *content, unsigned int number)
{
	int length;

	length = ft_len_u(number);
	if (content->width > length)
		length = content->width;
	if (content->precision > length)
		length = content->precision;
	return (length);
}

void	u_conversion(t_format *content, va_list args)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	content->length_output = length_output_u(content, number);
	format_pos_nbr(content, number);
}
