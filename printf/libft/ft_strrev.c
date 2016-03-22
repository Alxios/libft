/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:20:48 by agaspar           #+#    #+#             */
/*   Updated: 2015/11/28 15:22:45 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *s)
{
	char	*str_end;
	char	c;

	str_end = s + ft_strlen(s) - 1;
	while (s < str_end)
	{
		c = *s;
		*s++ = *str_end;
		*str_end-- = c;
	}
}
