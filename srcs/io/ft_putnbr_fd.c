/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:28:55 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/22 17:33:05 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static void		ft_putnbr_uni_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_uni_fd(n / 10, fd);
		ft_putnbr_uni_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	ft_putnbr_uni_fd(n, fd);
}
