/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:48:52 by videsvau          #+#    #+#             */
/*   Updated: 2017/01/13 08:03:26 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_manage_fd(int fd, t_list **chain)
{
	t_list	*tmp;

	tmp = *chain;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, fd);
	tmp->content_size = fd;
	ft_lstadd(chain, tmp);
	tmp = *chain;
	return (tmp);
}

int		ft_stroccur(char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		if (src[i] == 10)
			return (i);
		i++;
	}
	return (i);
}

void	banana(t_list **alst, char *tmp)
{
	free((*alst)->content);
	(*alst)->content = tmp;
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*chain;
	t_list			*curr;
	char			buff[BUFF_SIZE + 1];
	int				end;
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	curr = ft_manage_fd(fd, &chain);
	while ((end = read(fd, buff, BUFF_SIZE)))
	{
		buff[end] = '\0';
		tmp = ft_strjoin(curr->content, buff);
		banana(&curr, tmp);
		if (ft_strchr(buff, 10))
			break ;
	}
	if (end < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	*line = ft_strsub(curr->content, 0, ft_stroccur(curr->content));
	tmp = ft_strsub(curr->content, ft_stroccur(curr->content) + 1,
			ft_strlen(curr->content) - ft_stroccur(curr->content));
	banana(&curr, tmp);
	return (1);
}
