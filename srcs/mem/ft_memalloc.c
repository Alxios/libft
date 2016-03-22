/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:27:45 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/22 16:22:42 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memalloc(size_t size)
{
	void *mall;

	mall = malloc(size);
	if (mall != NULL)
		return (ft_memset(mall, 0, size));
	else
		return (NULL);
}
