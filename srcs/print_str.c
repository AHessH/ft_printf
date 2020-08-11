/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 02:10:14 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/11 14:50:30 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	take_len(t_qual *arg_type, char *str)
{
	int len;

	len = ft_strlen(str);
	if (arg_type->accur < 0)
	{
		arg_type->len = len;
		return ;
	}
	arg_type->len = len > arg_type->accur ? arg_type->accur : len;
}

static void	put_crop_str(char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar(*str);
		str++;
		i++;
	}
}

int			print_str(t_qual *arg_type, va_list arg)
{
	char	*str;
	t_bool	is_nil;

	is_nil = false;
	str = va_arg(arg, char*);
	if (arg_type->width < 0)
	{
		arg_type->width = arg_type->width * -1;
		arg_type->hyphen = true;
	}
	if (arg_type->accur == 0 && !arg_type->width)
		return (1);
	if (!str && (is_nil = true))
		if (!(str = ft_strdup("(null)")))
			return (-1);
	take_len(arg_type, str);
	if (!arg_type->hyphen)
		ft_print_space(arg_type->width - arg_type->len);
	put_crop_str(str, arg_type->len);
	if (arg_type->hyphen)
		ft_print_space(arg_type->width - arg_type->len);
	if (is_nil)
		free(str);
	return (ft_max(arg_type->width, arg_type->len));
}
