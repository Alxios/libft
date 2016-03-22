/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:49:10 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 13:49:30 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar_fd(wchar_t c, int fd)
{
	if (c <= 0x7f)
		ft_putchar_fd(c, fd);
	else if (c <= 0x7ff)
	{
		ft_putchar_fd((c >> 6) + 0xc0, fd);
		ft_putchar_fd((c & 0x3f) + 0x80, fd);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar_fd((c >> 12) + 0xe0, fd);
		ft_putchar_fd(((c >> 6) & 0x3f) + 0x80, fd);
		ft_putchar_fd((c & 0x3f) + 0x80, fd);
	}
	else
	{
		ft_putchar_fd((c >> 18) + 0xf0, fd);
		ft_putchar_fd(((c >> 12) & 0x3f) + 0x80, fd);
		ft_putchar_fd(((c >> 6) & 0x3f) + 0x80, fd);
		ft_putchar_fd((c & 0x3f) + 0x80, fd);
	}
}
