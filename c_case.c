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

int	ccase(char c, t_p_format *info)
{
	int		i;

	i = 1;
	if (info->width > 1 && !(info->minus))
	{
		while (i < info->width)
		{
			ft_putchar(' ');
			i++;
		}
	}
	ft_putchar(c);
	if (info->width > 1 && info->minus)
	{
		while (i < info->width)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (i);
}

int	ischarinset(char c)
{
	int		i;
	char	*set;

	set = "cspdiuxX%%";
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (i);
		i++;
	}
	return (999);
}
