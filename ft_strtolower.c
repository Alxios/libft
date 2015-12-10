/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:31:27 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/01 12:58:52 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *s)
{
	unsigned int	i;
	char			*t;

	i = 0;
	t = ft_strnew(ft_strlen(s));
	while (s[i] != '\0')
	{
		t[i] = ft_tolower(s[i]);
		i++;
	}
	return (t);
}
