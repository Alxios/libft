/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:30:09 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/22 16:22:52 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)src;
	while (len--)
	{
		if (*ptr == (unsigned char)c)
			return ((void*)ptr);
		ptr++;
	}
	return (NULL);
}
