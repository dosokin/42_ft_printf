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

char	*pmincase(void)
{
	char	*r;

	r = malloc (6 * sizeof(char));
	if (!r)
		return (0);
	r[0] = '(';
	r[1] = 'n';
	r[2] = 'i';
	r[3] = 'l';
	r[4] = ')';
	r[5] = 0;
	return (r);
}

int	dividplen(unsigned long long p)
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

void	flag_manage_p1(unsigned long long n, t_p_format *infos, t_xdata *data)
{
	data->l = dividplen(n);
	if (infos->point && infos->precision)
		infos->zero = 0;
	if (infos->point && (infos->precision > data->l))
		data->zeros = infos->precision - data->l;
	if ((infos->width > infos->precision + infos->hashtag
			+ data->l) && infos->zero)
		data->zeros = data->zeros + (infos->width - (infos->precision
					+ infos->hashtag + data->l));
}

void	p_to_s_process(unsigned long long n, t_p_format *infos, int i, char *r)
{
	int		x;

	x = 87;
	if (n / 16 != 0)
		p_to_s_process(n / 16, infos, (i - 1), r);
	if (n % 16 < 10)
		r[i] = ((n % 16) + '0');
	else
		r[i] = ((n % 16) + x);
}

void	flag_manage_p2(t_p_format *infos, t_xdata *data, int x, char *r)
{
	if (infos->hashtag)
	{
		r[data->j++] = '0';
		r[data->j++] = 33 + x;
		infos->hashtag = 0;
	}
	while (data->zeros--)
		r[data->j++] = '0';
}
