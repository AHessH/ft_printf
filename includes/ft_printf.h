/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:34:20 by froxanne          #+#    #+#             */
/*   Updated: 2020/07/11 14:56:20 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "t_bool.h"
# include "../libft/libft.h"

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# define MOD_NO		0
# define MOD_SHORT	'h'
# define MOD_CHAR	's'
# define MOD_LONG	'l'
# define MOD_LL		'B'
# define MOD_BL		'L'

typedef long long int	t_llint;
typedef unsigned long long int	t_ullint;
typedef unsigned long int		t_ulint;

typedef struct	s_f_type
{
	char		*whole;
	char		*frac;
	int			f_len;
	int			w_len;
}				t_f_type;

typedef struct	s_qual
{
	t_bool		hyphen;
	t_bool		p_sing;
	t_bool		space;
	t_bool		sharp;
	t_bool		zero;
	int			width;
	int			accur;
	char		modif;
	char		conver;
	int			len;
}				t_qual;

int				ft_printf(const char *str, ...);

/*
** Qual func.
*/
void			clear_qual(t_qual *qual);

/*
** Parse func.
*/
int				parse(const char **str, t_qual *arg_type, va_list arg);
int				parse_flags(const char **str, t_qual *arg_type);
int				parse_modif(const char **str, t_qual *arg_type);
int				parse_width(const char **str, t_qual *arg_type);
int				parse_accur(const char **str, t_qual *arg_type);
void			parse_conver(const char **str, t_qual *arg_type);
void			set_if_asters(int aster, va_list arg, t_qual *arg_type);

/*
** Print func.
*/
int				print_arg(va_list arg, t_qual *arg_type, int counter);

int				print_chars(t_qual *arg_type, va_list arg);
int				print_str(t_qual *arg_type, va_list arg);
int				print_num(t_qual *arg_type, va_list arg);
int				print_u_num(t_qual *arg_type, va_list arg);
int				print_x_num(t_qual *arg_type, va_list arg);
int				print_p(t_qual *arg_type, va_list arg);
int				print_perc(t_qual *arg_type);
int				print_f_num(t_qual *arg_type, va_list arg);

/*
** Help func
*/
void			sharp_str(char c);
int				sharp_x(t_bool c);
void			take_ulen_10_b(t_qual *arg_type, t_ullint num);
t_bool			take_len_10_b(t_qual *arg_type, t_llint num);
void			take_len_16_b(t_qual *arg_type, t_ullint num);

#endif
