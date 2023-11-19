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

char	*ucase(unsigned int u, t_p_format *infos, int i, char *r)
{
	t_udata	*data;

	if (infos->point)
		if (infos->precision == 0 && u == 0)
			return (r);
	data = init_u_data(u);
	if (data->o)
	{
		data->o = 0;
		i = lenset_ucase(u, infos, data, i);
		r = malloc((i + 1) * sizeof(char));
		if (!r)
		{
			free(data);
			return (NULL);
		}
		r[i--] = 0;
	}
	flag_manage_u(infos, data, r);
	u_to_s_process(u, infos, i, r);
	free (data);
	return (r);
}
