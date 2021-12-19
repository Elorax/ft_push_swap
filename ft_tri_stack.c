/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:28:25 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/19 16:52:08 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int max_itab(t_itab a)
{
	int	i;
	int max;
	int	i_max;

	i = 0;
	i_max = 0;
	max = a.tab[0];
	while (i < a.size)
	{
		if (max < a.tab[i])
		{
			max = a.tab[i];
			i_max = i;
		}
		i++;
	}
	return (i_max);
}

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
		//old part

//		while (a->tab[0] > parsing[i])
//			rotate(*a, 1);
		


		ft_remonter(a, max_itab(*a));
		rotate(*a, 1);
		i++;
	}
	free(parsing);
}
