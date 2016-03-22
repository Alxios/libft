/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:19:42 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 17:15:50 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*get_prefix(intmax_t nbr, t_printf *ptrf)
{
	char	*prefix;

	prefix = NULL;
	if (nbr < 0)
		prefix = ft_strdup("-");
	else if (nbr >= 0 && (ptrf->pf_flag & FLAG_SIGN))
		prefix = ft_strdup("+");
	else if (nbr >= 0 && (ptrf->pf_flag & FLAG_SPACE))
		prefix = ft_strdup(" ");
	return (prefix);
}

size_t		type_int(va_list *args, t_printf *ptrf)
{
	intmax_t	nbr;
	size_t		length;
	char		*format;
	char		*prefix;

	if (ptrf->pf_flag & FLAG_WIDTH && ptrf->pf_flag & FLAG_PRECISION)
		ptrf->pf_flag &= ~FLAG_ZERO;
	nbr = length_cast(va_arg(*args, intmax_t), ptrf);
	prefix = get_prefix(nbr, ptrf);
	if (nbr < 0)
		nbr = -nbr;
	format = syntax_numeric(nbr, 10, ptrf);
	length = (format ? ft_strlen(format) : 0)
		+ (prefix ? ft_strlen(prefix) : 0);
	put_prev(length, ptrf, prefix);
	if (format != NULL)
	{
		ft_putstr(format);
		ft_strdel(&format);
	}
	if (ptrf->width && ptrf->pf_flag & FLAG_RIGHT)
		ft_putchar_while(' ', ptrf->width - length);
	return (FT_MAX(ptrf->width, length));
}
