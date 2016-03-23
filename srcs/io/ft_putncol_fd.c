/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:14:36 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/23 14:29:37 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	ft_putncol_fd(char const *s, int const length, unsigned int color,
		int fd)
{
	ft_putstr_fd("\033[38;5;", fd);
	ft_putnbr_fd(color, fd);
	ft_putstr_fd("m", fd);
	ft_putnstr_fd(s, length, fd);
	ft_putstr_fd("\033[0m", fd);
}
