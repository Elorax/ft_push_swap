/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:28:25 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/26 14:00:35 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_tri_stack(t_itab *a, t_itab *b)
{
	int	*parsing;
	int	i;

	i = 2;
	parsing = find_parsing(*a);
	while (i < parsing[0] + 2)
	{
		ft_chunk_to_stack(a, b, parsing, i);
		while ((b->size))
			ft_push_stack(a, b);
		while (a->tab[0] > parsing[i])
			rotate(*a);
		i++;
	}
	free(parsing);
}
