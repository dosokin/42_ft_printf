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

t_udata	*init_u_data(unsigned int u)
{
	t_udata	*data;

	data = malloc(sizeof(t_udata));
	if (!data)
		return (NULL);
	data->j = 0;
	data->z = 0;
	data->len = dividixlenuns(u);
	data->o = 1;
	return (data);
}

int	lenset_ucase(unsigned int u, t_p_format *infos, t_udata *data, int i)
{
	int		o;

	o = 0;
	if (infos->point && infos->precision)
		infos->zero = 0;
	if (infos->precision > data->len)
		data->z = infos->precision - data->len;
	if (infos->space)
		o++;
	else if (infos->plus)
		o++;
	i = dividixlenuns(u) + o + data->z;
	return (i);
}

void	flag_manage_u(t_p_format *infos, t_udata *data, char *r)
{
	if (infos->space)
	{
		r[data->j++] = ' ';
		infos->space = 0;
	}
	if (infos->plus)
	{
		r[data->j++] = '+';
		infos->plus = 0;
	}
	while (data->z-- > 0)
		r[data->j++] = '0';
}

void	u_to_s_process(unsigned int u, t_p_format *infos, int i, char *r)
{
	if (u / 10 != 0)
		u_to_s_process(u / 10, infos, (i - 1), r);
	r[i] = ((u % 10) + '0');
}
