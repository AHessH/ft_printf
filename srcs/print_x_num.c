/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 02:28:12 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/11 15:20:11 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_ullint	type_cast(t_qual *arg_type, va_list arg)
{
	t_ullint num;

	if (arg_type->modif == MOD_SHORT)
		num = (unsigned short int)va_arg(arg, unsigned int);
	else if (arg_type->modif == MOD_CHAR)
		num = (unsigned char)va_arg(arg, unsigned int);
	else if (arg_type->modif == MOD_LONG)
		num = (unsigned long int)va_arg(arg, unsigned long);
	else if (arg_type->modif == MOD_LL)
		num = (t_ullint)va_arg(arg, t_ullint);
	else
		num = (unsigned int)va_arg(arg, unsigned int);
	return (num);
}

static int		put_x_num(t_ullint num, t_qual *arg_type)
{
	char *str;

	if (arg_type->conver == 'x')
	{
		if (!(str = ft_ullitoa(num, 16, "0123456789abcdef")))
			return (-1);
	}
	else if (!(str = ft_ullitoa(num, 16, "0123456789ABCDEF")))
		return (-1);
	ft_putstr(str);
	free(str);
	return (1);
}

static int		right_align(t_qual *arg_type, t_ullint num)
{
	if (arg_type->accur != -1)
	{
		ft_print_space(arg_type->width -
			ft_max(arg_type->len, arg_type->accur) - sharp_x(arg_type->sharp));
		if (arg_type->sharp && num)
			sharp_str(arg_type->conver);
	}
	else if (arg_type->zero)
	{
		if (arg_type->sharp && num)
			sharp_str(arg_type->conver);
		ft_putchars(arg_type->width - ft_max(arg_type->len,
			arg_type->accur) - sharp_x(arg_type->sharp), '0');
	}
	else
	{
		ft_print_space(arg_type->width - ft_max(arg_type->len,
			arg_type->accur) - sharp_x(arg_type->sharp));
		if (arg_type->sharp && num)
			sharp_str(arg_type->conver);
	}
	ft_putchars(arg_type->accur - arg_type->len, '0');
	if (put_x_num(num, arg_type) == -1)
		return (-1);
	return (1);
}

int				print_x_num(t_qual *arg_type, va_list arg)
{
	t_ullint	num;

	num = type_cast(arg_type, arg);
	take_len_16_b(arg_type, num);
	if (arg_type->accur == 0 && num == 0)
	{
		ft_print_space(arg_type->width);
		return (arg_type->width);
	}
	else if (arg_type->hyphen)
	{
		if (arg_type->sharp && num)
			sharp_str(arg_type->conver);
		ft_putchars(arg_type->accur - arg_type->len -
			sharp_x(arg_type->sharp), '0');
		if (put_x_num(num, arg_type) == -1)
			return (-1);
		ft_print_space(arg_type->width -
			ft_max(arg_type->len, arg_type->accur) - sharp_x(arg_type->sharp));
	}
	else if (right_align(arg_type, num) == -1)
		return (-1);
	return (ft_max(arg_type->width, ft_max(arg_type->len, arg_type->accur)) +
		(arg_type->width == 0 && arg_type->sharp && num != 0 ? 2 : 0));
}
