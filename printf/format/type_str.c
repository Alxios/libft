/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:20:05 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 15:43:33 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	type_str(va_list *args, t_printf *ptrf)
{
	char		*str;
	size_t		length;

	if (ptrf->len == l)
		return (type_wstr(args, ptrf));
	str = va_arg(*args, char*);
	if (str == NULL)
		str = "(null)";
	length = ft_strlen(str);
	if (ptrf->pf_flag & FLAG_PRECISION)
		length = FT_MIN(length, ptrf->precision);
	put_prev(length, ptrf, NULL);
	ft_putnstr(str, length);
	if (ptrf->width && ptrf->pf_flag & FLAG_RIGHT)
		ft_putchar_while(' ', ptrf->width - length);
	return (FT_MAX(ptrf->width, length));
}
