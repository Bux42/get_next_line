/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:44 by videsvau          #+#    #+#             */
/*   Updated: 2017/01/13 05:07:00 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	length;
	int		i;

	i = 0;
	if (!s2 && !s1)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char*)malloc(sizeof(char) * length)))
		return (NULL);
	length = 0;
	while (length < ft_strlen(s1))
		str[i++] = s1[length++];
	length = 0;
	while (length < ft_strlen(s2))
		str[i++] = s2[length++];
	str[i] = '\0';
	return (str);
}
