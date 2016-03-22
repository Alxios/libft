/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:34:35 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/22 16:23:29 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	if (n == 0)
		return (s);
	ptr = (unsigned char*)s;
	while (n > 0)
	{
		*ptr++ = (unsigned char)c;
		n--;
	}
	return (s);
}
