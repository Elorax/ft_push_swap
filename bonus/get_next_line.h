/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:50:16 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/26 02:48:13 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "../libft/libft.h"
typedef struct s_count
{
	char	end;
}	t_count;

typedef struct s_buf
{
	char	buffer[BUFFER_SIZE + 1];
	int		memo;
	int		begin;
}	t_buf;

void	*ft_strndup(char const *s, int begin, int end);
t_list	*ft_lstnnew(void *s, int begin, int end);
void	ft_char_swap(char *a, char *b);
void	clean_buffer(t_buf *reader);
void	check_eol(int fd, t_count *count, t_buf *reader, t_list **lst);
char	*ft_makeline(t_list *lst, int n);
char	*get_next_line(int fd);

#endif
