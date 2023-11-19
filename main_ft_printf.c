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

void	no_percent(const char *format, t_main_data *data)
{
	while (format[data->i] != '%' && format[data->i])
	{
		ft_putchar(format[data->i]);
		data->i++;
		data->y++;
	}
}

static void	f_eight_case(const char *format, t_main_data *data)
{
	if (doublepercent(format, data->i_base + 1) == 0)
	{
		ft_putchar('%');
		data->y++;
		while (format[data->i_base + 1] != '%')
		{
			ft_putchar(format[data->i_base + 1]);
			data->i_base++;
			data->y++;
		}
		data->i--;
		data->skip = 1;
	}
	else
	{
		ft_putchar('%');
		data->y++;
	}
}

static void	no_format(const char *format, t_main_data *data)
{
	if (doublepercent(format, data->i_base + 1) && data->skip == 0)
	{
		data->y = -1;
		data->i--;
	}
	else
	{
		ft_putchar('%');
		data->y++;
		data->i = data->i_base;
	}
}

static void	other_branches(const char *format, t_main_data *data)
{
	if (data->f == 8)
		f_eight_case(format, data);
	else if (data->f == 999)
		no_format(format, data);
}

void	f_branches(const char *format, t_main_data *data, va_list args)
{
	if (data->f == 0)
		data->y += ccase(va_arg(args, int), data->flag);
	else if (data->f == 1)
		data->y += scase(va_arg(args, char *), data->flag, 0, 10);
	else if (data->f == 3 || data->f == 4)
		data->y += scase(dicase(va_arg(args, int), data->flag, 1, data->r),
				data->flag, data->flag->zero, 1);
	else if (data->f == 5)
		data->y += scase(ucase(va_arg(args, int), data->flag, 1, data->r),
				data->flag, data->flag->zero, 1);
	else if (data->f == 6)
		data->y += scase(lil_xcase(va_arg(args, unsigned int),
					data->flag, 1, data->r), data->flag, data->flag->zero, 4);
	else if (data->f == 7)
		data->y += scase(big_xcase(va_arg(args, unsigned int),
					data->flag, 1, data->r), data->flag, data->flag->zero, 4);
	else if (data->f == 2)
	{
		data->p = ((unsigned long long)va_arg(args, unsigned long int));
		data->y += scase(pcase(data->p, data->flag, 1, data->r),
				data->flag, data->flag->zero, 4);
	}
	else
		other_branches(format, data);
}
