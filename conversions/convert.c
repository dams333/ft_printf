/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:23:20 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/02 16:26:00 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conversion(char conv, t_flags flags, va_list *ap)
{
	if (conv == 'c')
		return (print_char(ap));
	if (conv == 's')
		return (print_str(ap));
	if (conv == 'p')
		return (print_ptr(flags, ap));
	if (conv == 'd')
		return (print_dbl(flags, ap));
	if (conv == 'i')
		return (print_int(flags, ap));
	if (conv == 'u')
		return (print_uint(ap));
	if (conv == 'x')
		return (print_hex(flags, ap));
	if (conv == 'X')
		return (print_hex_cap(flags, ap));
	return (0);
}

t_bool	is_conversion(char c)
{
	if (c == 'c')
		return (TRUE);
	if (c == 's')
		return (TRUE);
	if (c == 'p')
		return (TRUE);
	if (c == 'd')
		return (TRUE);
	if (c == 'i')
		return (TRUE);
	if (c == 'u')
		return (TRUE);
	if (c == 'x')
		return (TRUE);
	if (c == 'X')
		return (TRUE);
	return (FALSE);
}
