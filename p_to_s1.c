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

t_p_format	*initinfo(void)
{
	t_p_format		*info;

	info = malloc(sizeof(t_p_format));
	if (!info)
		return (NULL);
	info->minus = 0;
	info->plus = 0;
	info->space = 0;
	info->hashtag = 0;
	info->zero = 0;
	info->width = 0;
	info->point = 0;
	info->precision = 0;
	info->negative = 0;
	return (info);
}

int	dividlen(unsigned int p)
{
	int			count;
	const int	base_hexa = 16;

	count = 1;
	while (p / base_hexa != 0)
	{
		count++;
		p = p / base_hexa;
	}
	return (count);
}

t_xdata	*init_x_data(void)
{
	t_xdata	*data;

	data = malloc(sizeof(t_xdata));
	if (!data)
		return (NULL);
	data->l = 0;
	data->j = 0;
	data->zeros = 0;
	return (data);
}

void	lil_x_to_s_process(unsigned int n, t_p_format *infos, int i, char *r)
{
	int		x;

	x = 87;
	if (n / 16 != 0)
		lil_x_to_s_process(n / 16, infos, (i - 1), r);
	if (n % 16 < 10)
		r[i] = ((n % 16) + '0');
	else
		r[i] = ((n % 16) + x);
}

void	big_x_to_s_process(unsigned int n, t_p_format *infos, int i, char *r)
{
	int		x;

	x = 55;
	if (n / 16 != 0)
		big_x_to_s_process(n / 16, infos, (i - 1), r);
	if (n % 16 < 10)
		r[i] = ((n % 16) + '0');
	else
		r[i] = ((n % 16) + x);
}
