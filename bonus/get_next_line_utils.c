/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:38:05 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/27 12:28:37 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_strndup(char const *s, int begin, int end)
{
	char	*dest;
	int		i;
	int		j;

	i = begin;
	j = 0;
	dest = (char *) malloc(sizeof(char) * (end - begin + 2));
	if (!dest)
		return (NULL);
	while (i <= end)
	{
		dest[j] = s[i];
		j++;
		i++;
	}
	dest[j] = 0;
	return (dest);
}

t_list	*ft_lstnnew(void *s, int begin, int end)
{
	t_list	*l;

	l = (t_list *) malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->content = ft_strndup((char *)s, begin, end);
	if (!(l->content))
	{
		free(l);
		return (NULL);
	}
	l->next = NULL;
	return (l);
}
