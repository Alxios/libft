/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:53:48 by agaspar           #+#    #+#             */
/*   Updated: 2015/11/26 17:56:10 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *tmp;

	tmp = dst;
	while (n > 0 && *src != '\0')
	{
		*tmp++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*tmp++ = '\0';
		n--;
	}
	return (dst);
}
