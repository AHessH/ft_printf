/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 11:23:51 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/11 14:48:33 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_llint	type_cast(t_qual *arg_type, va_list arg)
{
	t_llint num;

	if (arg_type->modif == MOD_SHORT)
		num = (short int)va_arg(arg, int);
	else if (arg_type->modif == MOD_CHAR)
		num = (char)va_arg(arg, int);
	else if (arg_type->modif == MOD_LONG)
		num = (long int)va_arg(arg, long);
	else if (arg_type->modif == MOD_LL)
		num = (t_llint)va_arg(arg, t_llint);
	else
		num = (int)va_arg(arg, int);
	return (num);
}

static int		put_llnbr(t_llint num, t_qual *arg_type, t_bool is_neg)
{
	char	*s_num;
	int		i;

	i = arg_type->len;
	if (is_neg)
		num *= -1;
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

static t_bool	check_and_print_sign(t_qual *arg_type, t_bool is_neg)
{
	t_bool sign;

	sign = (is_neg || arg_type->p_sing || arg_type->space);
	if (is_neg)
		ft_putchar('-');
	else if (!is_neg && (arg_type->p_sing || arg_type->space))
		ft_putchar(arg_type->p_sing ? '+' : ' ');
	return (sign);
}

static int		right_align(t_qual *arg_type, t_bool is_neg, t_llint num)
{
	t_bool sign;

	sign = (is_neg || arg_type->p_sing || arg_type->space);
	if (arg_type->accur != -1)
	{
		ft_print_space(arg_type->width -
			ft_max(arg_type->len, arg_type->accur) - sign);
		sign = check_and_print_sign(arg_type, is_neg);
	}
	else if (arg_type->zero)
	{
		sign = check_and_print_sign(arg_type, is_neg);
		ft_putchars(arg_type->width -
			ft_max(arg_type->len, arg_type->accur) - sign, '0');
	}
	else
	{
		ft_print_space(arg_type->width -
			ft_max(arg_type->len, arg_type->accur) - sign);
		sign = check_and_print_sign(arg_type, is_neg);
	}
	ft_putchars(arg_type->accur - arg_type->len, '0');
	if (put_llnbr(num, arg_type, is_neg) == -1)
		return (-1);
	return (1);
}

int				print_num(t_qual *arg_type, va_list arg)
{
	t_llint	num;
	t_bool	is_neg;
	t_bool	sign;

	num = type_cast(arg_type, arg);
	is_neg = take_len_10_b(arg_type, num);
	sign = (is_neg || arg_type->p_sing || arg_type->space);
	if (arg_type->accur == 0 && num == 0)
	{
		ft_putchars(arg_type->width, ' ');
		return (arg_type->width);
	}
	else if (arg_type->hyphen)
	{
		sign = check_and_print_sign(arg_type, is_neg);
		ft_putchars(arg_type->accur - arg_type->len, '0');
		if (put_llnbr(num, arg_type, is_neg) == -1)
			return (-1);
		ft_print_space(arg_type->width -
			ft_max(arg_type->len, arg_type->accur) - sign);
	}
	else if (right_align(arg_type, is_neg, num) == -1)
		return (-1);
	return (ft_max(arg_type->width, (ft_max(arg_type->len,
		arg_type->accur))) + ((arg_type->width == 0 && sign) ? 1 : 0));
}
