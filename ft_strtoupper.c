/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:27:49 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/01 12:58:18 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *s)
{
	int		i;
	char	*t;

	i = 0;
	t = ft_strnew(ft_strlen(s));
	while (s[i] != '\0')
	{
		t[i] = ft_toupper(s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}
