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

void	ft_putstr_col(char const *s, unsigned int color)
{
	ft_putstr_fd("\033[38;5;", 1);
	ft_putnbr_fd(color, 1);
	ft_putstr_fd("m", 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\033[0m", 1);
}
