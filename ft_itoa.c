/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:11:24 by agaspar           #+#    #+#             */
/*   Updated: 2015/11/28 18:31:45 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charlen(unsigned int n)
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

char		*ft_itoa(int n)
{
	int				i;
	unsigned int	j;
	char			*tmp;

	i = 0;
	tmp = ft_strnew(ft_charlen(n));
	j = n;
	if (n < 0)
		j = -n;
	if (j == 0)
		tmp[i++] = '0';
	while (j > 0)
	{
		tmp[i++] = j % 10 + '0';
		j /= 10;
	}
	if (n < 0)
		tmp[i++] = '-';
	tmp[i] = '\0';
	ft_strrev(tmp);
	return (tmp);
}
