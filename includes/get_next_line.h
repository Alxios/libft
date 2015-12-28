/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:36:55 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/18 17:35:30 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <fcntl.h>
# include <unistd.h>

int				get_next_line(int const fd, char **map);

typedef struct	s_lstfd
{
	int				fd;
	char			*content;
	struct s_lstfd	*next;
}				t_lstfd;

#endif
