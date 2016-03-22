/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:09:15 by agaspar           #+#    #+#             */
/*   Updated: 2015/11/27 13:54:28 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s == NULL)
		return (NULL);
	new = ft_strnew(len);
	if (new)
	{
		s += start;
		i = 0;
		while (i < len)
		{
			new[i] = s[i];
			i++;
		}
		return (new);
	}
	return (NULL);
}
