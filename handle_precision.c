/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:16:21 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:58:54 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	var_precision(int *index, t_format *content, va_list args)
{
	content->precision = va_arg(args, int);
	if (content->precision < 0)
		content->precision = -1;
	*index = *index + 1;
}

int		handle_prec(char *format, int *index, t_format *content, va_list args)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	content->precision = -1;
	if (format[*index + i] == '.')
	{
		content->precision = 0;
		i++;
		if (format[*index + i] == '*')
			var_precision(index, content, args);
		else if (ft_isdigit(format[*index + i]))
		{
			while (ft_isdigit(format[*index + i]))
				i++;
			if (!(s = ft_substr(format, *index + 1, i)))
				return (-1);
			content->precision = ft_atoi(s);
		}
	}
	free(s);
	*index += i;
	return (0);
}
