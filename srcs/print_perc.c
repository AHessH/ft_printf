/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:40:44 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/11 14:50:21 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_perc(t_qual *arg_type)
{
	if (!arg_type->zero)
	{
		if (!arg_type->hyphen)
			ft_print_space(arg_type->width - 1);
		ft_putchar('%');
		if (arg_type->hyphen)
			ft_print_space(arg_type->width - 1);
	}
	else
	{
		if (!arg_type->hyphen)
			ft_putchars(arg_type->width - 1, '0');
		ft_putchar('%');
		if (arg_type->hyphen)
			ft_putchars(arg_type->width - 1, '0');
	}
	return (ft_max(1, arg_type->width));
}
