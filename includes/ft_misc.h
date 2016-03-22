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

size_t		ft_strlen(const char *s);
int			ft_atoi(const char *nptr);

char		*ft_itoa(unsigned long n);

char		**ft_range(char **map, size_t n);
int			ft_tablen(char **map);
size_t		ft_nbrlen(long nbr);
size_t		ft_nbrlen_base(long n, int const base);
size_t		ft_strlen_c(char const *str, char c);

char		*ft_ultoabase(unsigned long nbr, size_t base);
int			ft_wcharlen(wchar_t c);
int			ft_wstrlen(wchar_t *str);

#endif
