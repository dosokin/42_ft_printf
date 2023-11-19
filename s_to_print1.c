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

int	nullpointer(t_p_format *info)
{
	char	*r;

	r = malloc(7 * sizeof(char));
	if (!r)
		return (0);
	r[0] = '(';
	r[1] = 'n';
	r[2] = 'u';
	r[3] = 'l';
	r[4] = 'l';
	r[5] = ')';
	r[6] = 0;
	return (scase(r, info, 0, 6));
}

t_s_ints	*init_data(char *s, t_p_format *info)
{
	t_s_ints	*data;

	data = malloc(sizeof(t_s_ints));
	if (!data)
		return (NULL);
	data->i = 0;
	data->j = ft_strlen(s) + info->negative + info->plus + info->space;
	data->y = 0;
	data->l = data->j;
	data->rr = 0;
	return (data);
}

int	null_s_case(int di_redirect, t_p_format *info)
{
	int		space;

	space = info->width;
	if (!(di_redirect == 1 || di_redirect == 4)
		&& info->point && info->precision < 6)
	{
		while (space--)
			ft_putchar(' ');
		return (info->width);
	}
	else
		return (nullpointer(info));
}

void	check_conds1(t_p_format *info, int di_redirect, t_s_ints *data)
{
	if (info->point && (di_redirect == 0 || di_redirect == 6))
	{
		if (info->precision < data->j)
		{
			data->l = info->precision;
			data->j = data->l;
			data->rr = data->rr + 1;
		}
	}
	if (info->negative && info->zero && (info->width >= data->l))
		write(1, "-", 1);
	if (info->space)
		ft_putchar(' ');
	if (info->plus)
		ft_putchar('+');
}
