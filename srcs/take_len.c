/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 09:15:19 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/01 09:27:20 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	take_ulen_10_b(t_qual *arg_type, t_ullint num)
{
	arg_type->len = 0;
	if (!num)
		arg_type->len = 1;
	while (num)
	{
		num /= 10;
		arg_type->len++;
	}
}

t_bool	take_len_10_b(t_qual *arg_type, t_llint num)
{
	t_bool is_neg;

	is_neg = false;
	arg_type->len = 0;
	if (!num)
		arg_type->len = 1;
	if (num < 0)
		is_neg = true;
	while (num)
	{
		num /= 10;
		arg_type->len++;
	}
	return (is_neg);
}

void	take_len_16_b(t_qual *arg_type, t_ullint num)
{
	arg_type->len = 0;
	if (!num)
		arg_type->len = 1;
	while (num)
	{
		num /= 16;
		arg_type->len++;
	}
}
