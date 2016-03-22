/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:17:19 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/01 12:52:30 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_range(char **map, size_t n)
{
	char			*str;
	unsigned int	i;

	str = NULL;
	i = 0;
	while (i < n - 1)
	{
		if (ft_strcmp(map[i], map[i + 1]) > 0)
		{
			str = map[i + 1];
			map[i + 1] = map[i];
			map[i] = str;
			i = 0;
		}
		else
			i++;
	}
	return (map);
}
