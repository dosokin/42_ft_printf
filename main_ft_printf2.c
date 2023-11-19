/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:14 by dosokin           #+#    #+#             */
/*   Updated: 2023/10/30 11:24:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	percent_manage(const char *format, t_main_data *data, va_list args)
{
	data->i_base = data->i;
	data->i++;
	data->flag = flagset(format, data->i);
	data->f = format_detect(format, data);
	f_branches(format, data, args);
	data->i++;
	free(data->flag);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_main_data	*data;
	int			char_printed;

	if (format == NULL)
		return (-1);
	data = init_main_data();
	va_start(args, format);
	while (format[data->i])
	{
		no_percent(format, data);
		if (format[data->i] == '%')
			percent_manage(format, data, args);
	}
	va_end(args);
	char_printed = data->y;
	free(data);
	return (char_printed);
}
