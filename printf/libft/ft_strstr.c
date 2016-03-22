/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:58:52 by agaspar           #+#    #+#             */
/*   Updated: 2015/11/25 17:35:21 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*temp_str;
	const char	*temp_tf;

	temp_tf = s2;
	if (*s2 == '\0')
		return (char *)s1;
	while (*s1 != '\0')
	{
		if (*s1 == *s2)
		{
			temp_str = s1;
			while (*temp_str++ == *temp_tf++)
			{
				if (*temp_tf == '\0')
					return (char *)s1;
			}
			temp_tf = (char *)s2;
		}
		s1++;
	}
	return (NULL);
}
