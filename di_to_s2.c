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

int	dividixlenuns(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

t_ddata	*init_di_data(int n)
{
	t_ddata	*data;

	data = malloc(sizeof(t_ddata));
	if (!data)
		return (NULL);
	data->j = 0;
	data->z = 0;
	data->len = dividixlen(n);
	data->o = 1;
	return (data);
}

int	lenset_dicase(int n, t_p_format *infos, int i, t_ddata *data)
{
	int	o;

	o = 0;
	if (n < 0)
		infos->space = 0;
	if (infos->point && infos->precision)
		infos->zero = 0;
	if (infos->precision > data->len)
		data->z = infos->precision - data->len;
	if (infos->space && (!infos->zero || (infos->zero
				&& infos->width <= data->len)))
		o++;
	if (n < 0 && (!infos->zero || (infos->zero && infos->width <= data->len)))
		o++;
	if (infos->plus && n >= 0 && (infos->width <= data->len
			|| infos->zero == 0))
		o++;
	i = dividixlen(n) + o + data->z;
	return (i);
}
