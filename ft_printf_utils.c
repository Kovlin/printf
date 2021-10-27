/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:30:16 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:29:26 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_x_zero(int x)
{
	while (x > 0)
	{
		ft_putchar_fd('0', 1);
		x--;
	}
}

void	ft_x_space(int x)
{
	while (x > 0)
	{
		ft_putchar_fd(' ', 1);
		x--;
	}
}
