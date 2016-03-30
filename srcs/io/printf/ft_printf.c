/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:40:15 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/30 18:13:57 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_type	get_format(char type)
{
	if (ft_tolower(type) == 'c' || type == '%')
		return (type_char);
	else if (type == 'i' || type == 'd')
		return (type_int);
	else if (ft_tolower(type) == 'x' || type == 'u' || type == 'o'
			|| type == 'b')
		return (type_unsigned);
	else if (type == 's')
		return (type_str);
	else if (type == 'S')
		return (type_wstr);
	else if (type == 'U' || type == 'O' || type == 'D')
		return (type_long);
	else if (type == 'p')
		return (type_pointer);
	return (type_char);
}

static size_t	options_parse(char **format, va_list *args, t_printf *ptrf)
{
	size_t	ret;
	t_type	type;

	parse_format(format, args, ptrf);
	type = get_format(**format);
	if (**format == '\0')
	{
		if (ptrf->sub_text)
		{
			ft_putstr(ptrf->sub_text);
			ft_strdel(&ptrf->sub_text);
		}
		return (0);
	}
	ptrf->type = **format;
	ret = type(args, ptrf);
	(*format)++;
	return (ret);
}

static int		print_result(const char *format, va_list *args, size_t length)
{
	t_printf	ptrf;
	char		*next;
	int			ret;

	if (*format == '\0')
		return (length);
	next = ft_strchr(format, '%');
	if (next == NULL)
	{
		ft_putstr(format);
		return (length + ft_strlen(format));
	}
	ft_bzero(&ptrf, sizeof(ptrf));
	if (next > format)
	{
		ptrf.sub_text = ft_strsub(format, 0, next - format);
		length += (next - format);
		format = next;
	}
	if ((ret = options_parse((char **)&format, args, &ptrf)) == -1)
		return (-1);
	length += ret;
	return (print_result(format, args, length));
}

int				ft_printf(const char *format, ...)
{
	va_list args;
	int		ret;

	ret = 0;
	va_start(args, format);
	ret = print_result(format, &args, 0);
	va_end(args);
	return (ret);
}
