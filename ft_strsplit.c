/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:10:47 by agaspar           #+#    #+#             */
/*   Updated: 2016/02/11 15:21:11 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_init_words(char const *s, char c, char **map)
{
	int		i;
	size_t	size;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			size = ft_strlen_c(s, c);
			map[i++] = ft_strsub(s, 0, size);
			s += size;
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
	if((map = malloc(sizeof(char *) * (ft_count_words(s, c) + 1))) == NULL)
		return (NULL);
	ft_init_words(s, c, map);
	return (map);
}
