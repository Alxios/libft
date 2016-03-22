/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:32:43 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 17:51:47 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	put_prev(const int length, t_printf *ptrf, char *prefix)
{
	if (ptrf->sub_text)
	{
		ft_putstr(ptrf->sub_text);
		ft_strdel(&ptrf->sub_text);
	}
	if (ptrf->pf_flag & FLAG_ZERO)
		ft_putstr(prefix ? prefix : "");
	if (ptrf->width && (~ptrf->pf_flag & FLAG_RIGHT))
		ft_putchar_while(ptrf->pf_flag & FLAG_ZERO ? '0' : ' '
				, ptrf->width - length);
	if (~ptrf->pf_flag & FLAG_ZERO)
		ft_putstr(prefix ? prefix : "");
	if (prefix)
		ft_strdel(&prefix);
}
