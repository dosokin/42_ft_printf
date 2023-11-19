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

void	info_precision(const char *format, int debut, int fin, t_p_format *info)
{
	int		precision;

	precision = 0;
	if (format[debut] == '.')
	{
		info->point = 1;
		debut++;
		while (debut < fin && ft_isnum(format[debut]))
		{
			precision = precision * 10 + (format[debut] - '0');
			debut++;
		}
	}
	info->precision = precision;
}

t_p_format	*flagdetect(const char *format, int debut, int fin)
{
	t_p_format	*info;

	info = initinfo();
	if (!info)
		return (NULL);
	debut = infoset1(format, debut, fin, info);
	debut = info_width(format, debut, fin, info);
	info_precision(format, debut, fin, info);
	return (info);
}

t_p_format	*flagset(const char *format, int i)
{
	int	debut;

	debut = i;
	while (ischarinset(format[i]) == 999 && format[i])
		i++;
	return (flagdetect(format, debut, i));
}

char	*ft_tolower(char *r)
{
	int		i;

	i = 0;
	while (r[i])
	{
		if (r[i] >= 65 && r[i] <= 90)
			r[i] = r[i] + 32;
		i++;
	}
	return (r);
}

int	divilen(unsigned long int p)
{
	int		d;

	d = 1;
	while (p / 16 != 0)
	{
		d++;
		p = p / 16;
	}
	return (d);
}
