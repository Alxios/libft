/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:11:24 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/14 18:33:56 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charlen(unsigned long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	else
		while (n > 0)
		{
			n /= 10;
			i++;
		}
	return (i);
}

char		*ft_itoa(unsigned long n)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(ft_charlen(n));
	if (tmp == NULL)
		return (NULL);
	if (n == 0)
		tmp[i++] = '0';
	while (n > 0)
	{
		tmp[i++] = n % 10 + '0';
		n /= 10;
	}
	tmp[i] = '\0';
	ft_strrev(tmp);
	return (tmp);
}
