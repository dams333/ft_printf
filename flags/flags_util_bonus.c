/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:25:56 by dhubleur          #+#    #+#             */
/*   Updated: 2021/11/26 10:21:23 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	is_flag(char c)
{
	if (c == '#')
		return (TRUE);
	if (c == ' ')
		return (TRUE);
	if (c == '+')
		return (TRUE);
	return (FALSE);
}

t_bool	is_already_flag(t_flags flags, char c)
{
	if (c == '#' && flags.alternate)
		return (TRUE);
	if (c == ' ' && flags.space)
		return (TRUE);
	if (c == '+' && flags.plus)
		return (TRUE);
	return (FALSE);
}

int	check_flags(const char *str, int i, t_flags *flags)
{
	int	j;

	j = 1;
	*flags = init_flags();
	while (str[i + j] && is_flag(str[i + j])
		&& !is_already_flag(*flags, str[i + j]))
	{
		if (str[i + j] == '#')
			flags->alternate = TRUE;
		if (str[i + j] == ' ')
			flags->space = TRUE;
		if (str[i + j] == '+')
			flags->plus = TRUE;
		j++;
	}
	if (is_conversion(str[i + j]))
	{
		return (j);
	}
	return (0);
}
