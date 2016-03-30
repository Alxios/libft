/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:32:43 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/30 18:52:21 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	parse_color(char *str)
{
	if (*str == '\0')
		return ;
	while (*str && str[0] != '{')
		ft_putchar(*str++);
	if (ft_strstr(str, "{red}"))
	{
		ft_putstr("\e[91m");
		str = ft_strchr(str, '}');
	}
	parse_color(str);
}

void	put_prev(const int length, t_printf *ptrf, char *prefix)
{
	if (ptrf->sub_text)
	{
		//ft_putstr(ptrf->sub_text);
		parse_color(ptrf->sub_text);
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
