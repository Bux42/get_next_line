/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 03:34:43 by videsvau          #+#    #+#             */
/*   Updated: 2017/01/13 03:59:37 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	lenght;
	int		i;

	i = 0;
	if (!s2 && !s1)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	lenght = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char*)malloc(sizeof(char) * lenght)))
		return (NULL);
	lenght = 0;
	while (lenght < ft_strlen(s1))
		str[i++] = s1[lenght++];
	lenght = 0;
	while (lenght < ft_strlen(s2))
		str[i++] = s2[lenght++];
	str[i] = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (str);
}
