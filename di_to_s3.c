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

int	n_sign_check(int n, t_p_format *infos, t_ddata *data, char *r)
{
	if (n < 0)
	{
		if (!infos->zero || (infos->zero && infos->width <= data->len))
			r[data->j] = '-';
		else
			infos->negative = 1;
		n = -n;
		data->j++;
		infos->plus = 0;
	}
	else if (infos->plus)
	{
		if ((infos->width <= data->len || infos->zero == 0))
		{
			r[data->j++] = '+';
			infos->plus = 0;
		}
	}
	return (n);
}

char	*di_to_s_process(int n, t_p_format *infos, int i, char *r)
{
	if (n / 10 != 0)
		di_to_s_process(n / 10, infos, (i - 1), r);
	r[i] = ((n % 10) + '0');
	return (r);
}

void	flag_manage_di(t_p_format *infos, char *r, t_ddata *data)
{
	if (infos->space && (!infos->zero || (infos->zero
				&& infos->width <= data->len)))
	{
		r[data->j++] = ' ';
		infos->space = 0;
	}
	while (data->z-- > 0)
		r[data->j++] = '0';
	free (data);
}

char	*case_n_null_prec_null(char *r, t_p_format *infos)
{
	if (infos->plus)
	{
		r = malloc(2 * sizeof(char));
		if (!r)
			return (NULL);
		r[0] = '+';
		r[1] = 0;
		infos->plus = 0;
	}
	return (r);
}
