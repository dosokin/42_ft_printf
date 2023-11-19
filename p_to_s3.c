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

void	flag_manage_x2(t_p_format *infos, t_xdata *data, int x, char *r)
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
