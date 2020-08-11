/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 04:07:49 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/11 14:50:51 by froxanne         ###   ########.fr       */
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

static int		put_ullnbr(t_ullint num, t_qual *arg_type)
{
	char		*s_num;
	int			i;

	i = arg_type->len;
	if (!(s_num = (char *)malloc(sizeof(char) * (arg_type->len + 1))))
		return (-1);
	s_num[arg_type->len] = 0;
	while (i--)
	{
		s_num[i] = num % 10 + '0';
		num /= 10;
	}
	ft_putstr_fd(s_num, 1);
	free(s_num);
	return (1);
}

static int		right_align(t_qual *arg_type, t_ullint num)
{
	if (arg_type->accur != -1)
	{
		ft_print_space(arg_type->width -
			ft_max(arg_type->len, arg_type->accur));
	}
	else if (arg_type->zero)
	{
		ft_putchars(arg_type->width -
			ft_max(arg_type->len, arg_type->accur), '0');
	}
	else
	{
		ft_print_space(arg_type->width -
			ft_max(arg_type->len, arg_type->accur));
	}
	ft_putchars(arg_type->accur - arg_type->len, '0');
	if (put_ullnbr(num, arg_type) == -1)
		return (-1);
	return (1);
}

int				print_u_num(t_qual *arg_type, va_list arg)
{
	t_ullint	num;

	num = type_cast(arg_type, arg);
	take_ulen_10_b(arg_type, num);
	if (arg_type->accur == 0 && num == 0)
	{
		ft_putchars(arg_type->width, ' ');
		return (arg_type->width);
	}
	else if (arg_type->hyphen)
	{
		ft_putchars(arg_type->accur - arg_type->len, '0');
		if (put_ullnbr(num, arg_type) == -1)
			return (-1);
		ft_print_space(arg_type->width -
			ft_max(arg_type->len, arg_type->accur));
	}
	else if (right_align(arg_type, num) == -1)
		return (-1);
	return (ft_max(arg_type->width, ft_max(arg_type->len, arg_type->accur)));
}
