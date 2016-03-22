/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:36:55 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/14 13:47:58 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*dst;

	i = ft_strlen(s);
	dst = (char*)malloc(sizeof(*dst) * (i + 1));
	if (dst == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dst[j] = s[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
