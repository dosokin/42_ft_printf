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

char	*dicase(int n, t_p_format *infos, int i, char *r)
{
	t_ddata	*data;

	if (n == -2147483648)
		return (intmincase(infos));
	if (infos->point)
		if (infos->precision == 0 && n == 0)
			return (case_n_null_prec_null(r, infos));
	data = init_di_data(n);
	if (data->o)
	{
		data->o = 0;
		i = lenset_dicase(n, infos, i, data);
		r = malloc((i + 1) * sizeof(char));
		if (!r)
		{
			free(data);
			return (NULL);
		}
		r[i--] = 0;
		n = n_sign_check(n, infos, data, r);
	}
	flag_manage_di(infos, r, data);
	return (di_to_s_process(n, infos, i, r));
}
