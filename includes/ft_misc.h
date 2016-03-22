/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:06:03 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/22 18:06:44 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MISC_H
# define FT_MISC_H

int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);
char		*ft_ultoabase(unsigned long nbr, size_t base);

char		**ft_range(char **map, size_t n);
int			ft_tablen(char **map);

size_t		ft_nbrlen(int nbr);
size_t		ft_nbrlen_base(long n, int const base);

int			ft_wcharlen(wchar_t c);
int			ft_wstrlen(wchar_t *str);

#endif
