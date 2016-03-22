/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_wstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:53:01 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 16:48:14 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static size_t	get_length(wchar_t *str, int precision)
{
	int		length;
	int		ret;

	length = 0;
	while (*str != '\0' && precision >= (ret = ft_wcharlen(*str)))
	{
		length += ret;
		precision -= ret;
	}
	return (length);
}

size_t			type_wstr(va_list *args, t_printf *ptrf)
{
	wchar_t		*str;
	size_t		length;

	str = va_arg(*args, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	length = ft_wstrlen(str);
	if (ptrf->pf_flag & FLAG_PRECISION)
		length = get_length(str, ptrf->precision);
	put_prev(length, ptrf, NULL);
	ft_putnwstr_fd(str, length, 1);
	if (ptrf->width && ptrf->pf_flag & FLAG_RIGHT)
		ft_putchar_while(' ', ptrf->width - length);
	return (FT_MAX(ptrf->width, length));
}
