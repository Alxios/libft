/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:08:42 by agaspar           #+#    #+#             */
/*   Updated: 2016/03/31 15:33:20 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "color.h"

# include <unistd.h>
# include <wchar.h>

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnstr(char const *s, int const len);
void	ft_putendl(char const *s);
void	ft_putcol(const char *s, unsigned int color);
void	ft_putncol(const char *s, const int length, unsigned int color);
void	ft_putwchar(wchar_t c);
void	ft_putwstr(wchar_t *str);
void	ft_putnwstr(wchar_t *str, int length);

void	ft_putnbr(int n);
void	ft_putnbr_ndl(int i);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putnstr_fd(char const *s, int const len, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putcol_fd(const char *s, unsigned int color, int fd);
void	ft_putncol_fd(const char *s, const int length, unsigned int color
		, int fd);
void	ft_putwchar_fd(wchar_t c, int fd);
void	ft_putwstr_fd(wchar_t *str, int fd);
void	ft_putnwstr_fd(wchar_t *str, int length, int fd);

void	ft_putenfr_fd(char const *s, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putchar_while(char c, int width);

int		get_next_line(int const fd, char **line);

#endif
