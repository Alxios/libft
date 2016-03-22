/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:19:11 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/18 14:41:58 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*get_prefix(intmax_t nbr, t_printf *ptrf)
{
	char	*prefix;

	prefix = NULL;
	if (ptrf->pf_flag & FLAG_PREFIX)
	{
		if (ft_tolower(ptrf->type) == 'x' || ptrf->type == 'p')
		{
			if (ptrf->type == 'p' || nbr != 0)
				prefix = ft_strdup(ptrf->type == 'X' ? "0X" : "0x");
		}
		else if (ft_tolower(ptrf->type) == 'o')
		{
			if ((nbr != 0 && ptrf->precision <= ft_nbrlen_base(nbr, 8))
				|| (nbr == 0 && ptrf->pf_flag & FLAG_PRECISION
					&& ptrf->precision == 0))
				prefix = ft_strdup("0");
		}
	}
	return (prefix);
}

static char	*get_result(intmax_t nbr, t_printf *ptrf)
{
	char	*result;

	result = NULL;
	if (ft_tolower(ptrf->type) == 'x' || ptrf->type == 'p')
	{
		result = syntax_numeric(nbr, 16, ptrf);
		if (ptrf->type == 'X' && result)
			ft_strtoupper(result);
	}
	else if (ft_tolower(ptrf->type) == 'b')
		result = syntax_numeric(nbr, 2, ptrf);
	else if (ft_tolower(ptrf->type) == 'o')
		result = syntax_numeric(nbr, 8, ptrf);
	else if (ft_tolower(ptrf->type) == 'u')
		result = syntax_numeric(nbr, 10, ptrf);
	return (result);
}

size_t		type_unsigned(va_list *args, t_printf *ptrf)
{
	char		*format;
	char		*prefix;
	size_t		length;
	intmax_t	nbr;

	if (ptrf->pf_flag & FLAG_WIDTH && ptrf->pf_flag & FLAG_PRECISION)
		ptrf->pf_flag &= ~FLAG_ZERO;
	nbr = length_cast_unit(va_arg(*args, uintmax_t), ptrf);
	prefix = get_prefix(nbr, ptrf);
	format = get_result(nbr, ptrf);
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
