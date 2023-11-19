/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionnal_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:14 by dosokin           #+#    #+#             */
/*   Updated: 2023/11/19 05:57:23 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_main_data	*init_main_data(void)
{
	t_main_data	*data;

	data = malloc(sizeof(t_main_data));
	if (!data)
		return (NULL);
	data->i = 0;
	data->f = 0;
	data->p = 0;
	data->flag = NULL;
	data->r = NULL;
	data->y = 0;
	data->i_base = 0;
	data->skip = 0;
	return (data);
}

int	is_a_flag(char c)
{
	char	*s;
	int		i;

	i = 0;
	s = "0# -+";
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

int	doublepercent(const char *format, int i)
{
	int	breakp;

	breakp = 0;
	while (format[i] != '%' && format[i])
	{
		if (is_a_flag(format[i]) && breakp == 0)
			i++;
		else if (breakp == 0)
			breakp++;
		else if (ft_isnum(format[i]) && breakp == 1)
			i++;
		else if (breakp == 1)
			breakp++;
		else if (format[i] == '.' && breakp == 2)
		{
			i++;
			breakp++;
		}
		else if (ft_isnum(format[i]) && breakp == 3)
			i++;
		else
			return (0);
	}
	return (1);
}
