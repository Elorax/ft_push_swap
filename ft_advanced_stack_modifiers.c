/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_stack_modifiers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:23:58 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/27 13:44:23 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_chunk_to_stack(t_itab *a, t_itab *b, int *parsing, int idx_pars)
{
	int	i;
	int	size;

	i = 0;
	size = a->size;
	while (i < size && parsing[idx_pars]
		&& (a->tab[0] <= parsing[idx_pars - 1] || idx_pars == 2))
	{
		if (a->tab[0] >= parsing[idx_pars]
			&& a->tab[0] <= parsing[idx_pars - 1])
			push(b, a);
		else
			rotate(*a);
		i++;
	}
}

void	ft_push_stack(t_itab *a, t_itab *b)
{
	int	max;
	int	min;
	int	i;

	min = 0;
	max = 0;
	i = 0;
	while (i < b->size)
	{
		if (b->tab[min] > b->tab[i])
			min = i;
		if (b->tab[max] < b->tab[i])
			max = i;
		i++;
	}
	ft_remonter(b, ft_find_closest(min, max, b->size));
	push(a, b);
	if (ft_find_closest(min, max, b->size + 1) == min)
		rotate(*a);
}
