/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:45:32 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/17 14:40:04 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*syntax_numeric(intmax_t nbr, int base, t_printf *ptrf)
{
	char	*value;
	char	*str;
	int		length;

	if (~ptrf->pf_flag & FLAG_PRECISION)
		return (ft_ultoabase(nbr, base));
	if (ptrf->precision == 0 && nbr == 0)
		return (NULL);
	value = ft_ultoabase(nbr, base);
	if (ptrf->precision > ft_strlen(value))
	{
		length = ptrf->precision - ft_strlen(value);
		str = ft_strnew(ptrf->precision);
		ft_memset(str, '0', sizeof(char) * length);
		ft_memmove(str + length, value, sizeof(char) * ft_strlen(value));
		free(value);
		return (str);
	}
	return (value);
}
