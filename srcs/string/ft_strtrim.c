/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:10:11 by agaspar           #+#    #+#             */
/*   Updated: 2016/02/11 15:29:30 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char const	*end;

	if (s == NULL)
		return (NULL);
	while (ft_isspace(*s))
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	end = s + ft_strlen(s) - 1;
	while (ft_isspace(*end))
		end--;
	return (ft_strsub(s, 0, end - s + 1));
}
