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

char	*pcase(unsigned long long n, t_p_format *infos, int i, char *r)
{
	t_xdata	*data;
	int		x;

	x = 87;
	infos->hashtag = 2;
	if (!n)
		return (pmincase());
	data = init_x_data();
	flag_manage_p1(n, infos, data);
	r = malloc((data->l + data->zeros + 3) * sizeof(char));
	if (!r)
	{
		free (data);
		return (NULL);
	}
	i = data->l + data->zeros + infos->hashtag;
	r[i--] = 0;
	flag_manage_p2(infos, data, x, r);
	p_to_s_process(n, infos, i, r);
	free (data);
	return (r);
}
