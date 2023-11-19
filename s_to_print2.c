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

void	main_content(char *s, t_s_ints *data, int di_redirect)
{
	while (s[data->i] && (data->i < data->l || di_redirect == 4))
	{
		write(1, &s[data->i], 1);
		data->i = data->i + 1;
		data->y = data->y + 1;
	}
}

void	su_width_manage(t_p_format *info, t_s_ints *data)
{
	if (info->width > data->l && (info->minus))
	{
		while (data->j < info->width)
		{
			ft_putchar(' ');
			data->j = data->j + 1;
		}
	}
}

int	point_trunc_case(t_p_format *info, t_s_ints *data)
{
	int		l;

	if (info->width > data->l)
	{
		free (data);
		return (info->width);
	}
	l = data->l;
	free (data);
	return (l);
}

int	scase(char *s, t_p_format *info, int x, int di_redirect)
{
	t_s_ints	*data;
	int			r;

	if (!s)
		return (null_s_case(di_redirect, info));
	if (di_redirect == 10)
	{
		info->space = 0;
		di_redirect = 0;
	}
	data = init_data(s, info);
	check_conds1(info, di_redirect, data);
	pre_width_manage(info, data, x);
	main_content(s, data, di_redirect);
	su_width_manage(info, data);
	if (di_redirect == 1 || di_redirect == 4 || di_redirect == 6)
		free(s);
	if (data->rr)
		return (point_trunc_case(info, data));
	r = data->y + (data->j - data->l) + info->negative;
	free (data);
	return (r);
}
