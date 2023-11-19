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

int	format_detect(const char *format, t_main_data *data)
{
	int		l;

	l = 0;
	while (ischarinset(format[data->i]) == 999 && format[data->i])
		data->i++;
	return (ischarinset(format[data->i]));
}

int	infoset1(const char *format, int debut, int fin, t_p_format *info)
{
	while (debut < fin && (ft_isnum(format[debut]) == 0 || format[debut] == '0')
		&& format[debut] != '.')
	{
		if (format[debut] == '-')
			info->minus = 1;
		else if (format[debut] == '+')
			info->plus = 1;
		else if (format[debut] == '#')
			info->hashtag = 2;
		else if (format[debut] == '0')
			info->zero = 1;
		else if (format[debut] == ' ')
			info->space = 1;
		debut++;
	}
	if (info->plus)
		info->space = 0;
	return (debut);
}

int	info_width(const char *format, int debut, int fin, t_p_format *info)
{
	int		nwidth;

	nwidth = 0;
	while (debut < fin && ft_isnum(format[debut]))
	{
		nwidth = nwidth * 10 + (format[debut] - '0');
		debut++;
	}
	info->width = nwidth;
	return (debut);
}
