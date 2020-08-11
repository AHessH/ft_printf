/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 04:10:32 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/11 14:37:18 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_arg(va_list arg, t_qual *arg_type, int counter)
{
	int res;

	res = 0;
	if (arg_type->conver == 'c')
		res = print_chars(arg_type, arg);
	else if (arg_type->conver == 's' && (res = print_str(arg_type, arg)) == -1)
		return (-1);
	else if (arg_type->conver == 'd' && (res = print_num(arg_type, arg)) == -1)
		return (-1);
	else if (arg_type->conver == 'u' &&
			(res = print_u_num(arg_type, arg)) == -1)
		return (-1);
	else if (arg_type->conver == 'p' && (res = print_p(arg_type, arg)) == -1)
		return (-1);
	else if ((arg_type->conver == 'x' || arg_type->conver == 'X') &&
		(res = print_x_num(arg_type, arg)) == -1)
		return (-1);
	else if (arg_type->conver == 'n')
		*va_arg(arg, int *) = counter;
	else if (arg_type->conver == '%')
		res = print_perc(arg_type);
	return (res);
}
