/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:19:03 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/14 18:18:15 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	type_pointer(va_list *args, t_printf *ptrf)
{
	ptrf->len = l;
	ptrf->pf_flag |= FLAG_PREFIX;
	return (type_unsigned(args, ptrf));
}
