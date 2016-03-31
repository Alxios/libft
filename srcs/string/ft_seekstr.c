/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seekstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 13:50:15 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/31 13:50:27 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_seekstr(const char **a, const char *b)
{
	const char	*str;
	int			len;

	str = *a;
	while (*b != '\0')
		if (*str++ != *b++)
			return (0);
	len = (str - *a);
	*a = str;
	return (len);
}
