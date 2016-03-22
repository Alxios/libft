/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:09:42 by agaspar           #+#    #+#             */
/*   Updated: 2015/11/30 12:03:23 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = NULL;
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new)
	{
		tmp = new;
		while (*s1)
			*new++ = *s1++;
		while (*s2)
			*new++ = *s2++;
	}
	return (tmp);
}
