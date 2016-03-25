/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:23:56 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/25 15:26:11 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long int	ft_atol(const char *str)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else
	{
		if (*str == '-')
		{
			sign = -1;
			str++;
		}
	}
	while (*str != '\0' && ft_isdigit(*str))
		nb = nb * 10 + (*str++ - '0');
	return (nb * sign);
}
