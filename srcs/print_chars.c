/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 19:14:16 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/11 14:47:35 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_chars(t_qual *arg_type, va_list arg)
{
	if (!arg_type->hyphen)
		ft_print_space(arg_type->width - 1);
	ft_putchar((unsigned char)va_arg(arg, int));
	if (arg_type->hyphen)
		ft_print_space(arg_type->width - 1);
	return (ft_max(arg_type->width, 1));
}
