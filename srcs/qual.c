/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qual.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froxanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 00:45:46 by froxanne          #+#    #+#             */
/*   Updated: 2020/06/21 05:00:56 by froxanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	clear_qual(t_qual *qual)
{
	qual->hyphen = false;
	qual->p_sing = false;
	qual->space = false;
	qual->sharp = false;
	qual->zero = false;
	qual->width = 0;
	qual->accur = -1;
	qual->modif = MOD_NO;
	qual->conver = 0;
	qual->len = 0;
}
