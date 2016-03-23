/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:14:36 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/23 14:25:24 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	ft_putncol(char const *s, int const length, unsigned int color)
{
	ft_putncol_fd(s, length, color, 1);
}
