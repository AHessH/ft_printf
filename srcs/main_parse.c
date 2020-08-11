/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 23:38:17 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/11 14:52:29 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse(const char **str, t_qual *arg_type, va_list arg)
{
	int aster;

	aster = 0;
	parse_flags(str, arg_type);
	if (!parse_width(str, arg_type))
		aster = 1;
	if (**str == '.')
		if ((*str)++ && !parse_accur(str, arg_type))
			aster += 2;
	parse_modif(str, arg_type);
	parse_conver(str, arg_type);
	if (aster)
		set_if_asters(aster, arg, arg_type);
	if (arg_type->width < 0)
	{
		arg_type->width = ft_abs(arg_type->width);
		arg_type->hyphen = true;
	}
	if (arg_type->accur < -1)
		arg_type->accur = -1;
	return (aster);
}

void	set_if_asters(int aster, va_list arg, t_qual *arg_type)
{
	if (aster == 1 || aster == 3)
		arg_type->width = (int)va_arg(arg, int);
	if (aster == 2 || aster == 3)
		arg_type->accur = (int)va_arg(arg, int);
}
