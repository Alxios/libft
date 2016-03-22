/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:46:51 by agaspar           #+#    #+#             */
/*   Updated: 2016/02/02 16:13:06 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int	read_line(int const fd, char **data)
{
	char	*buf;
	int		ret;
	char	*tmp;
	char	*sub;

	buf = ft_strnew(BUFF_SIZE);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret > 0)
	{
		if ((tmp = ft_strchr(buf, '\0')))
		{
			sub = ft_strsub(buf, 0, tmp - buf);
			tmp = ft_strjoin(*data, sub);
			free(sub);
		}
		else
			tmp = ft_strjoin(*data, buf);
		if (!tmp)
			return (-1);
		free(*data);
		*data = tmp;
		free(buf);
	}
	return (ret);
}

static int	get_next_line_lst(int const fd, char **line, char **data)
{
	char	*save;
	int		ret;

	if (!*data && (*data = ft_strnew(0)) == NULL)
		return (-1);
	save = ft_strchr(*data, '\n');
	while (save == NULL)
	{
		ret = read_line(fd, data);
		if (ret < 0)
			return (-1);
		if (ret != 0)
			save = ft_strchr(*data, '\n');
		else if ((save = ft_strchr(*data, '\0')) == *data)
			return (0);
	}
	*line = ft_strsub(*data, 0, ft_strlen(*data) - ft_strlen(save));
	if (ft_strcmp(save, "\n") != 0)
		*data = ft_strdup(save + 1);
	else
	{
		ft_strdel(data);
		*data = NULL;
	}
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static t_lstfd	data;
	t_lstfd			*tmp;

	tmp = &data;
	if (fd < 0 || !line)
		return (-1);
	if (tmp->content == NULL)
	{
		data.fd = fd;
		data.next = NULL;
		return (get_next_line_lst(fd, line, &tmp->content));
	}
	while (tmp->next != NULL && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp->fd != fd)
	{
		tmp->next = malloc(sizeof(t_lstfd));
		tmp->next->fd = fd;
		tmp->next->content = NULL;
		tmp->next->next = NULL;
		return (get_next_line_lst(fd, line, &tmp->next->content));
	}
	return (get_next_line_lst(fd, line, &tmp->content));
}
