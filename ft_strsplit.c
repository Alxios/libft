/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:10:47 by agaspar           #+#    #+#             */
/*   Updated: 2016/02/01 16:33:20 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_init_words(char const *s, char c, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			j = 0;
			map[i] = ft_strnew(ft_strlen_c(s, c));
			if (map[i])
				while (*s != c && *s != '\0')
					map[i][j++] = *s++;
			i++;
		}
		if (*s != '\0')
			s++;
	}
	map[i] = NULL;
}

static int		ft_count_words(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != c && *s != '\0')
				s++;
			i++;
		}
		if (*s != '\0')
			s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**map;

	if (s == NULL || c == 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * ft_count_words(s, c) + 1);
	if (map)
		ft_init_words(s, c, map);
	return (map);
}
