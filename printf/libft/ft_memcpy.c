/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:32:18 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/10 14:01:01 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*strdst;
	char	*strsrc;

	if (len == 0 || dst == src)
		return (dst);
	strdst = (char*)dst;
	strsrc = (char*)src;
	while (len > 0)
	{
		*strdst++ = *strsrc++;
		len--;
	}
	return (dst);
}
