/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:06:50 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/31 15:48:29 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_color_light(const char **str)
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

static char	*set_style(const char **str)
{
	if (ft_seekstr(str, "b"))
		return (ft_strdup(BOLD));
	else if (ft_seekstr(str, "d"))
		return (ft_strdup(DIM));
	else if (ft_seekstr(str, "u"))
		return (ft_strdup(UNDERLINED));
	else if (ft_seekstr(str, "r"))
		return (ft_strdup(REVERSE));
	else if (ft_seekstr(str, "h"))
		return (ft_strdup(HIDDEN));
	return (NULL);
}

static char	*set_color(const char **str)
{
	const char	*color[8] = {"black", "red", "green", "yellow", "blue",
		"magenta", "cyan", "grey"};
	char		*out;
	int			i;

	i = 0;
	out = ft_strdup("\033[3#m");
	if (ft_seekstr(str, "light_"))
		out[2] = '9';
	while (i < 8)
		if (ft_seekstr(str, color[i++]))
		{
			out[3] = i + '0' - 1;
			return (out);
		}
	ft_strdel(&out);
	return (set_color_light(str));
}

static char	*extra(const char **str)
{
	char	*out;
	char	*tmp;
	char	*tmp2;

	out = set_color(str);
	while (ft_seekstr(str, ";") && out != NULL)
	{
		tmp = out;
		out = ft_strjoin(out, tmp2 = set_style(str));
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	if (ft_seekstr(str, "}") && out != NULL)
		return (out);
	ft_strdel(&out);
	return (NULL);
}

void		parse_extra(const char *str)
{
	char	*tmp;
	char	*out;

	while (*str)
	{
		if (ft_seekstr(&str, "{"))
		{
			tmp = (char *)str - 1;
			if ((out = extra(&str)) != NULL)
			{
				ft_putstr(out);
				ft_strdel(&out);
				continue;
			}
			str = tmp;
		}
		ft_putchar(*str++);
	}
}
