/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:29:27 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/22 16:22:47 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (NULL);
	while (i < len)
	{
		*((char *)dst + i) = *((char *)src + i);
		if (*((char *)src + i) == (char)c)
		{
			return ((char *)dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
