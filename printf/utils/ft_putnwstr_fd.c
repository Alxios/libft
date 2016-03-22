/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:48:28 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 13:48:45 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr_fd(wchar_t *str, int length, int fd)
{
	while (*str && length >= ft_wcharlen(*str))
	{
		length = length - ft_wcharlen(*str);
		ft_putwchar_fd(*str++, fd);
	}
}
