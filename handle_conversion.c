/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:22:13 by rlinkov           #+#    #+#             */
/*   Updated: 2020/01/22 17:55:44 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		handle_conversion(char *format, int *index, int *res, va_list args)
{
	t_format	*content;

	if (!(content = (t_format*)malloc(sizeof(t_format))))
		return (-1);
	if (handle_param(format, index, content, args) == -1)
	{
		free(content);
		return (-1);
	}
	*res += content->length_output;
	free(content);
	return (0);
}
