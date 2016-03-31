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

char	*set_color_light(const char **str)
{
	if (ft_seekstr(str, "white"))
		return (ft_strdup(WHITE));
	else if (ft_seekstr(str, "default"))
		return (ft_strdup(DEFAULT));
	else if (ft_seekstr(str, "eoc"))
		return (ft_strdup(EOC));
	else if (ft_seekstr(str, "light_grey"))
		return (ft_strdup(LIGHT_GREY));
	return (NULL);
}

char	*set_style(const char **str)
{
	if (ft_seekstr(str, "b"))
		return ft_strdup(BOLD);
	else if (ft_seekstr(str, "d"))
		return ft_strdup(DIM);
	else if (ft_seekstr(str, "u"))
		return ft_strdup(UNDERLINED);
	else if (ft_seekstr(str, "r"))
		return ft_strdup(REVERSE);
	else if (ft_seekstr(str, "h"))
		return ft_strdup(HIDDEN);
	return (NULL);
}

char	*set_color(const char **str)
{
	int		i;
	char	*out;
	char	*color[10];

	i = 0;
	out = ft_strdup("\e[##m");
	ft_seekstr(str, "light_") ?
		(out[2] = '9') : (out[2] = '3');
	color[0] = "black";
	color[1] = "red";
	color[2] = "green";
	color[3] = "yellow";
	color[4] = "blue";
	color[5] = "magenta";
	color[6] = "cyan";
	color[7] = "grey";
	while (i < 8)
		if (ft_seekstr(str, color[i++]))
		{
			out[3] = i + '0' - 1;
			return (out);
		}
	ft_strdel(&out);
	return (set_color_light(str));
}

void	parse_extra(const char *str)
{
	char	*tmp;
	char	*out;

	while (*str)
	{
		if (*str == '{')
		{
			tmp = (char *)str;
			str++;
			out = set_color(&str);
			while (ft_seekstr(&str, ";"))
				out = ft_strjoin(set_style(&str), out);
			if (ft_seekstr(&str, "}") && out != NULL)
			{
				ft_putstr(out);
				ft_strdel(&out);
				continue;
			}
			ft_strdel(&out);
			str = tmp;
		}
		ft_putchar(*str++);
	}
}

void	put_prev(const int length, t_printf *ptrf, char *prefix)
{
	if (ptrf->sub_text)
	{
		parse_extra(ptrf->sub_text);
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
