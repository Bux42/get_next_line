/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:48:52 by videsvau          #+#    #+#             */
/*   Updated: 2017/01/31 20:53:22 by videsvau         ###   ########.fr       */
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
	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmp->content = "";
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

void	join(t_list **alst, char *buff, int end)
{
	char	*ret;

	ret = NULL;
	(*alst)->content = ft_strdup((*alst)->content);
	if ((ret = (char*)malloc(sizeof(char)
	* ft_strlen((*alst)->content) + end + 1)) == NULL)
		return ;
	ft_strcpy(ret, (*alst)->content);
	ft_strncat(ret, buff, end);
	free((*alst)->content);
	(*alst)->content = ret;
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*chain;
	t_list			*curr;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				end;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) == -1)
		return (-1);
	curr = ft_manage_fd(fd, &chain);
	while (!ft_strchr(curr->content, 10) && (end = read(fd, buff, BUFF_SIZE)))
		join(&curr, buff, end);
	if (end < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	*line = ft_strsub(curr->content, 0, ft_stroccur(curr->content));
	tmp = ft_strsub(curr->content, ft_stroccur(curr->content) + 1,
			ft_strlen(curr->content) - ft_stroccur(curr->content));
	free((curr->content));
	(curr)->content = tmp;
	//ft_putnbr(ft_strlen(curr->content));ft_putchar('\t');
	return (1);
}
