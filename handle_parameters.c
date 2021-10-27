/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parameters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:23:39 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:36:57 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_param(char *format, int *index, t_format *content, va_list args)
{
	handle_flags(format, index, content);
	if (handle_width(format, index, content, args) == -1)
		return (-1);
	if (handle_prec(format, index, content, args) == -1)
		return (-1);
	handle_spec(format, index, content, args);
	return (0);
}
