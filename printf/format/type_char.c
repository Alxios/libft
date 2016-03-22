/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:19:19 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 15:23:46 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	type_char(va_list *args, t_printf *ptrf)
{
	size_t		length;
	wchar_t		c;

	if (ft_tolower(ptrf->type) == 'c')
		c = va_arg(*args, unsigned int);
	else
		c = ptrf->type;
	if (ptrf->type == 'C' || ptrf->len == l)
	{
		if ((length = ft_wcharlen(c)) == -1)
			return (-1);
		put_prev(length, ptrf, NULL);
		ft_putwchar_fd(c, 1);
	}
	else
	{
		put_prev(1, ptrf, NULL);
		ft_putchar(c);
		length = 1;
	}
	if (ptrf->width && ptrf->pf_flag & FLAG_RIGHT)
		ft_putchar_while(' ', ptrf->width - length);
	return (FT_MAX(ptrf->width, length));
}
