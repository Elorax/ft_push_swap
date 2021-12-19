/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_stack_modifiers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:23:58 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/19 16:35:22 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_chunk_to_stack(t_itab *a, t_itab *b, int *parsing, int idx_pars)
{
	int	i;
	int	size;

	i = 0;
	size = a->size;
	//On fait size operations.
	//Condition du while a modifier.
	while (i < size
		&& (a->tab[0] <= parsing[idx_pars - 1] || idx_pars == 2))
	{
		//Si le premier element de a est dans le chunk, on le push
		if ((a->tab[0] > parsing[idx_pars] || (a->tab[0] == parsing[idx_pars]
					&& idx_pars == parsing[0] + 1))
			&& a->tab[0] <= parsing[idx_pars - 1])
			push(b, a, 1);
		else//Sinon on rotate
		{
			rotate(*a, 1);
		}
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
	push(a, b, 1);
	if (ft_find_closest(min, max, b->size + 1) == min)
		rotate(*a, 1);
}
