/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:14:36 by agaspar           #+#    #+#             */
/*   Updated: 2016/01/27 15:41:33 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putcol_fd(char const *s, unsigned int color, int fd)
{
	ft_putstr_fd("\033[38;5;", fd);
	ft_putnbr_fd(color, fd);
	ft_putstr_fd("m", fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\033[0m", fd);
}
