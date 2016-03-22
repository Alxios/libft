/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:16:53 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 16:37:56 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

intmax_t	length_cast(intmax_t nbr, t_printf *ptrf)
{
	if (ptrf->len == hh)
		return ((char)nbr);
	else if (ptrf->len == h)
		return ((short int)nbr);
	else if (ptrf->len == l)
		return ((long int)nbr);
	else if (ptrf->len == ll)
		return ((long long int)nbr);
	else if (ptrf->len == j)
		return ((intmax_t)nbr);
	else if (ptrf->len == z)
		return ((size_t)nbr);
	return ((int)nbr);
}

uintmax_t	length_cast_unit(uintmax_t nbr, t_printf *ptrf)
{
	if (ptrf->len == hh)
		return ((unsigned char)nbr);
	else if (ptrf->len == h)
		return ((unsigned short int)nbr);
	else if (ptrf->len == l)
		return ((unsigned long int)nbr);
	else if (ptrf->len == ll)
		return ((unsigned long long int)nbr);
	else if (ptrf->len == j)
		return ((uintmax_t)nbr);
	else if (ptrf->len == z)
		return ((size_t)nbr);
	return ((unsigned int)nbr);
}
