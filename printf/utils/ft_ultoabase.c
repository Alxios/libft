/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:20:23 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 14:40:27 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charlen(unsigned long n, size_t base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	else
		while (n > 0)
		{
			n /= base;
			i++;
		}
	return (i);
}

char		*ft_ultoabase(unsigned long n, size_t base)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(ft_charlen(n, base));
	if (tmp == NULL)
		return (NULL);
	if (n == 0)
		tmp[i++] = '0';
	while (n > 0)
	{
		tmp[i++] = (n % base) > 9 ? (n % base) - 10 + 'a' : (n % base) + '0';
		n /= base;
	}
	tmp[i] = '\0';
	ft_strrev(tmp);
	return (tmp);
}
