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

void	flag_manage_x1(unsigned int n, t_p_format *infos, t_xdata *data)
{
	data->l = dividlen(n);
	if (infos->point && infos->precision)
		infos->zero = 0;
	if (infos->point && (infos->precision > data->l))
		data->zeros = infos->precision - data->l;
	if ((infos->width > infos->precision + infos->hashtag + data->l)
		&& infos->zero)
		data->zeros = data->zeros
			+ (infos->width - (infos->precision + infos->hashtag + data->l));
}

char	*lil_xcase(unsigned int n, t_p_format *infos, int i, char *r)
{
	t_xdata	*data;

	if (!n)
	{
		if (infos->point && !infos->precision)
			return (NULL);
		infos->hashtag = 0;
	}
	data = init_x_data();
	flag_manage_x1(n, infos, data);
	r = malloc((data->l + data->zeros + 1 + infos->hashtag) * sizeof(char));
	if (!r)
	{
		free (data);
		return (NULL);
	}
	i = data->l + data->zeros + infos->hashtag;
	r[i--] = 0;
	flag_manage_x2(infos, data, 87, r);
	lil_x_to_s_process(n, infos, i, r);
	free (data);
	return (r);
}

char	*big_xcase(unsigned int n, t_p_format *infos, int i, char *r)
{
	t_xdata	*data;

	if (!n)
	{
		if (infos->point && !infos->precision)
			return (NULL);
		infos->hashtag = 0;
	}
	data = init_x_data();
	flag_manage_x1(n, infos, data);
	r = malloc((data->l + data->zeros + 1 + infos->hashtag) * sizeof(char));
	if (!r)
	{
		free (data);
		return (NULL);
	}
	i = data->l + data->zeros + infos->hashtag;
	r[i--] = 0;
	flag_manage_x2(infos, data, 55, r);
	big_x_to_s_process(n, infos, i, r);
	free (data);
	return (r);
}
