/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:32:43 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/30 19:15:28 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	set_color(char **str)
{
	if (ft_strstr(*str, "{red}") == *str)
		ft_putstr("\e[91m");
	else if (ft_strstr(*str, "{green}") == *str)
		ft_putstr("\e[32m");
	else if (ft_strstr(*str, "{eoc}") == *str)
		ft_putstr("\e[0m");
	else
	{
		ft_putchar(*(*str)++);
		return ;
	}
	*str = ft_strchr(*str, '}');
	(*str)++;
}

void	parse_color(char *str)
{
	if (*str == '\0')
		return ;
	while (*str)
	{
		if (*str == '{')
		{
			set_color(&str);
			continue;
		}
		ft_putchar(*str++);
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
