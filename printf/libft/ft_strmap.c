/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:02:32 by agaspar           #+#    #+#             */
/*   Updated: 2015/11/30 11:57:25 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*new;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	if (new)
	{
		i = 0;
		while (s[i] != '\0')
		{
			new[i] = f(s[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
