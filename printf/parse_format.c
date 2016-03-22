/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:45:59 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 17:39:14 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		parse_width(char **format, va_list *args, t_printf *ptrf)
{
	int wildcard;

	ptrf->pf_flag |= FLAG_WIDTH;
	ptrf->width = 0;
	if (**format == '*')
	{
		wildcard = va_arg(*args, int);
		if (wildcard < 0)
		{
			ptrf->pf_flag |= FLAG_RIGHT;
			wildcard = -wildcard;
		}
		ptrf->width = wildcard;
		return ;
	}
	while (ft_isdigit(**format))
		ptrf->width = ptrf->width * 10 + (*(*format)++ - '0');
	(*format)--;
}

static void		parse_precision(char **format, va_list *args, t_printf *ptrf)
{
	int wildcard;

	ptrf->pf_flag |= FLAG_PRECISION;
	ptrf->precision = 0;
	if (*(*format + 1) == '*')
	{
		wildcard = va_arg(*args, int);
		if (wildcard < 0)
			ptrf->pf_flag &= ~FLAG_PRECISION;
		else
			ptrf->precision = wildcard;
		(*format)++;
		return ;
	}
	while (ft_isdigit(*(*format + 1)))
		ptrf->precision = ptrf->precision * 10 + (*++(*format) - '0');
}

static void		fixe_confit(t_printf *ptrf)
{
	if (ptrf->pf_flag & FLAG_RIGHT)
		ptrf->pf_flag &= ~FLAG_ZERO;
	if (ptrf->pf_flag & FLAG_SIGN)
		ptrf->pf_flag &= ~FLAG_SPACE;
}

static t_length	parse_length(char **format, t_printf *ptrf)
{
	if (**format == 'h')
	{
		if (*++(*format) == 'h')
			return (FT_MAX(hh, ptrf->len));
		(*format)--;
		return (FT_MAX(h, ptrf->len));
	}
	if (**format == 'l')
	{
		if (*++(*format) == 'l')
			return (FT_MAX(ll, ptrf->len));
		(*format)--;
		return (FT_MAX(l, ptrf->len));
	}
	else if (**format == 'j')
		return (FT_MAX(j, ptrf->len));
	else if (**format == 'z')
		return (FT_MAX(z, ptrf->len));
	return (FT_MAX(none, ptrf->len));
}

void			parse_format(char **format, va_list *args, t_printf *ptrf)
{
	while (*(*format)++)
	{
		if (**format == '#')
			ptrf->pf_flag |= FLAG_PREFIX;
		else if (**format == '0')
			ptrf->pf_flag |= FLAG_ZERO;
		else if (**format == '-')
			ptrf->pf_flag |= FLAG_RIGHT;
		else if (**format == '+')
			ptrf->pf_flag |= FLAG_SIGN;
		else if (**format == ' ')
			ptrf->pf_flag |= FLAG_SPACE;
		else if (ft_isdigit(**format) || **format == '*')
			parse_width(format, args, ptrf);
		else if (**format == '.')
			parse_precision(format, args, ptrf);
		else if (**format == 'h' || **format == 'l' || **format == 'j'
				|| **format == 'z')
			ptrf->len = parse_length(format, ptrf);
		else
			break ;
	}
	fixe_confit(ptrf);
}
