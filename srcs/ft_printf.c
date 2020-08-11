/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:33:29 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/11 14:56:06 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		sharp_str(char c)
{
	ft_putstr((c == 'x') ? "0x" : "0X");
}

int			sharp_x(t_bool c)
{
	return ((c == FALSE) ? 0 : 2);
}

static int	prf(const char **str, t_qual *arg_type)
{
	int		len;

	len = 0;
	clear_qual(arg_type);
	while (**str && **str != '%')
	{
		ft_putchar(**str);
		len++;
		(*str)++;
	}
	return (len);
}

int			ft_printf(const char *str, ...)
{
	va_list		arg;
	int			count;
	t_qual		arg_type;
	t_llint		len;
	int			tmp;

	tmp = 0;
	len = 0;
	if (!str && !*str)
		return (0);
	count = 0;
	va_start(arg, str);
	while (str && *str)
	{
		len += prf(&str, &arg_type);
		if (!*str)
			break ;
		str++;
		parse(&str, &arg_type, arg);
		if ((tmp = print_arg(arg, &arg_type, count)) == -1)
			return (-1);
		len += tmp;
		count++;
	}
	return (len);
}
