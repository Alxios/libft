/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_format.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:45:32 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 17:36:02 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_FORMAT_H
# define HANDLER_FORMAT_H

# include <sys/types.h>
# include <stdarg.h>
# include <stdint.h>

# define FLAG_PREFIX 0000001
# define FLAG_ZERO 0000002
# define FLAG_RIGHT 0000004
# define FLAG_SIGN 0000010
# define FLAG_SPACE 0000020
# define FLAG_WIDTH 0000040
# define FLAG_PRECISION 0000100

typedef enum	e_lenght {
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_length;

typedef struct	s_printf
{
	unsigned int	pf_flag;
	size_t			width;
	size_t			precision;
	enum e_lenght	len;
	char			type;
	char			*sub_text;
}				t_printf;

typedef size_t	(*t_type)(va_list*, t_printf*);

void			parse_format(char **format, va_list *args, t_printf *ptrf);

size_t			type_char(va_list *args, t_printf *ptrf);
size_t			type_str(va_list *args, t_printf *ptrf);
size_t			type_int(va_list *args, t_printf *ptrf);
size_t			type_unsigned(va_list *args, t_printf *ptrf);
size_t			type_pointer(va_list *args, t_printf *ptrf);
size_t			type_wstr(va_list *args, t_printf *ptrf);
size_t			type_long(va_list *args, t_printf *ptrf);

void			put_prev(const int length, t_printf *ptrf, char *prefix);

char			*syntax_numeric(intmax_t nbr, int base, t_printf *ptrf);
intmax_t		length_cast(intmax_t nbr, t_printf *ptrf);
uintmax_t		length_cast_unit(uintmax_t nbr, t_printf *ptrf);

#endif
