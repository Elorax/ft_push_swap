/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:51:31 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/26 13:58:17 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include <unistd.h>

typedef struct s_itab
{
	int		*tab;
	int		size;
	char	pile;
}	t_itab;

void	ft_swap(int *a, int *b);
void	swap(t_itab a);
void	push(t_itab *a, t_itab *b);
void	rotate(t_itab a);
void	reverse_rotate(t_itab a);
int		is_arg_valid(char *s);
void	ft_remonter(t_itab *a, int index);
int		ft_init_stacks(int nb, char **av, t_itab *a, t_itab *b);
void	ft_display_stacks(t_itab a, t_itab b);
void	ft_stack_of_3(t_itab *a);
void	ft_calcul_mins(t_itab *a, int *min, int *max);
void	ft_tri_rapide(t_itab *a, t_itab *b);
int		ft_find_closest(int a, int b, int size);
void	ft_remonter(t_itab *a, int index);
int		calcul_nb_pasring(int size);
void	ft_push_stack(t_itab *a, t_itab *b);
int		*find_parsing(t_itab a);		//renommer en build parsing ?
void	ft_chunk_to_stack(t_itab *a, t_itab *b, int *parsing, int idx_pars);
void	ft_tri_stack(t_itab *a, t_itab *b);
int		ft_is_stack_sorted(t_itab a);
int		is_arg_valid(char *s);
int		ft_is_stack_valid(t_itab a);

#endif
