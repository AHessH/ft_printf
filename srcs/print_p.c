/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 07:36:47 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/11 14:49:33 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_p(t_qual *arg_type, va_list arg)
{
	t_ulint	point;
	char	*s_p;

	point = (t_ulint)va_arg(arg, t_ulint);
	if (!point)
	{
		if (!arg_type->hyphen)
			ft_putchars(arg_type->width - 3, ' ');
		ft_putstr("0x0");
		if (arg_type->hyphen)
			ft_putchars(arg_type->width - 3, ' ');
		return (ft_max(arg_type->width, 3));
	}
	if (!(s_p = ft_ullitoa(point, 16, "0123456789abcdef")))
		return (-1);
	arg_type->len = ft_strlen(s_p);
	if (!arg_type->hyphen)
		ft_putchars(arg_type->width - 2 - arg_type->len, ' ');
	ft_putstr("0x");
	ft_putstr(s_p);
	if (arg_type->hyphen)
		ft_putchars(arg_type->width - 2 - arg_type->len, ' ');
	free(s_p);
	return (ft_max(arg_type->width, arg_type->len + 2));
}
