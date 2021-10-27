/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:14:42 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:30:48 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_len_hexa(unsigned int nbr)
{
	int i;

	i = 0;
	while (nbr / 16 != 0)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i + 1);
}

void	ft_putnbr_hexa(unsigned int nbr, int check)
{
	char *base;

	base = "0123456789abcdef";
	if (check == 1)
		base = "0123456789ABCDEF";
	if (nbr / 16 != 0)
		ft_putnbr_hexa(nbr / 16, check);
	write(1, &base[nbr % 16], 1);
}

int		ft_len_hexa_p(unsigned long nbr)
{
	int i;

	i = 0;
	while (nbr / 16 != 0)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i + 3);
}

void	ft_putnbr_hexa_p(unsigned long nbr, int check)
{
	char *base;

	if (check == 1)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
	}
	base = "0123456789abcdef";
	if (nbr / 16 != 0)
		ft_putnbr_hexa_p(nbr / 16, 0);
	write(1, &base[nbr % 16], 1);
}
