/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:11:20 by agaspar           #+#    #+#             */
/*   Updated: 2015/11/27 13:51:54 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char			*tmp_str;
	char			*tmp_tf;
	unsigned int	tmp_len;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0' && len > 0)
	{
		if (*s1 == *s2)
		{
			tmp_len = len;
			tmp_str = (char *)s1;
			tmp_tf = (char *)s2;
			while (*tmp_str++ == *tmp_tf++ && len > 0)
			{
				if (*tmp_tf == '\0')
					return ((char *)s1);
				len--;
			}
			len = tmp_len;
		}
		len--;
		s1++;
	}
	return (NULL);
}
