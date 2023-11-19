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

t_minn	*init_min_data(void)
{
	t_minn	*data;

	data = malloc(sizeof(t_minn));
	if (!data)
		return (NULL);
	data->resultat = NULL;
	data->minint = "2147483648";
	data->zeros = 0;
	data->i = 0;
	data->j = 0;
	return (data);
}

char	*intmincase_result(t_minn *data)
{
	char	*res;

	res = ft_strdup((const char *)data->resultat);
	free(data->resultat);
	free(data);
	return (res);
}

char	*intmincase(t_p_format *infos)
{
	t_minn	*data;

	data = init_min_data();
	infos->space = 0;
	infos->plus = 0;
	if (infos->point && infos->precision)
		infos->zero = 0;
	if (infos->width > 11 && infos->zero)
		infos->negative = 1;
	if (infos->precision > 10)
		data->zeros = infos->precision - 10;
	data->resultat = malloc ((12 + data->zeros) * sizeof(char));
	if (!data->resultat)
		return (NULL);
	if (!infos->negative)
		data->resultat[data->i++] = '-';
	while (data->zeros--)
		data->resultat[data->i++] = '0';
	while (data->minint[data->j])
		data->resultat[data->i++] = data->minint[data->j++];
	data->resultat[data->i] = 0;
	return (intmincase_result(data));
}

int	dividixlen(int n)
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
