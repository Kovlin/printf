/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:25:49 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:57:04 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	var_width(int *index, t_format *content, va_list args)
{
	content->width = va_arg(args, int);
	if (content->width < 0)
	{
		content->width *= -1;
		content->flags = 1;
	}
	*index = *index + 1;
}

int		handle_width(char *format, int *index, t_format *content, va_list args)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	content->width = 0;
	if (format[*index + i] == '*')
		var_width(index, content, args);
	else if (ft_isdigit(format[*index + i]))
	{
		while (ft_isdigit(format[*index + i]))
			i++;
		if (!(s = ft_substr(format, *index, i)))
			return (-1);
		content->width = ft_atoi(s);
	}
	free(s);
	*index += i;
	return (0);
}
