/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 01:10:25 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/02 04:43:09 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_conver(const char **str, t_qual *arg_type)
{
	if (ft_isconver(**str))
		arg_type->conver = **str;
	arg_type->conver = (arg_type->conver == 'i') ? 'd' : arg_type->conver;
	(*str)++;
}

int		parse_accur(const char **str, t_qual *arg_type)
{
	if (**str == '*' && (*str)++)
		return (0);
	arg_type->accur = ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
	return (1);
}

int		parse_width(const char **str, t_qual *arg_type)
{
	if (**str == '*' && (*str)++)
		return (0);
	arg_type->width = ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
	return (1);
}

int		parse_modif(const char **str, t_qual *arg_type)
{
	int modif;

	modif = 0;
	while (**str && (modif = ft_ismodif(**str)))
	{
		if (**str == MOD_LONG)
			arg_type->modif = (arg_type->modif == MOD_LONG) ? MOD_LL : MOD_LONG;
		else if (**str == MOD_SHORT)
			arg_type->modif = (arg_type->modif == MOD_SHORT) ?
									MOD_CHAR : MOD_SHORT;
		else if (**str == MOD_BL)
			arg_type->modif = MOD_BL;
		(*str)++;
	}
	return (0);
}

int		parse_flags(const char **str, t_qual *arg_type)
{
	while (**str && ft_isflags(**str))
	{
		if (**str && **str == '-')
			arg_type->hyphen = true;
		else if (**str && **str == '+')
			arg_type->p_sing = true;
		else if (**str && **str == ' ')
			arg_type->space = true;
		else if (**str && **str == '#')
			arg_type->sharp = true;
		else if (**str && **str == '0')
			arg_type->zero = true;
		(*str)++;
	}
	return (0);
}
