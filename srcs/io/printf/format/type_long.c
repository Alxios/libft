/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:51:25 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 13:51:39 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	type_long(va_list *args, t_printf *ptrf)
{
	ptrf->len = l;
	if (ptrf->type == 'D')
		return (type_int(args, ptrf));
	return (type_unsigned(args, ptrf));
}
