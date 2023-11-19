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

void	pre_width_manage(t_p_format *info, t_s_ints *data, int x)
{
	if (info->width > data->l && !(info->minus))
	{
		if (x)
		{
			while (data->j < info->width)
			{
				ft_putchar('0');
				data->j++;
			}
		}
		else
		{
			while (data->j < info->width)
			{
				ft_putchar(' ');
				data->j++;
			}
		}
	}
}
