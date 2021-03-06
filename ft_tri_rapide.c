/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_rapide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:17:36 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/27 12:58:35 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_of_3(t_itab *a)
{
	if (a->size == 2)
	{
		if (a->tab[0] > a->tab[1])
			swap(*a, 1);
	}
	else if (a->tab[0] < a->tab[1] && a->tab[1] < a->tab[2])
		return ;
	else if (a->tab[0] < a->tab[1] && a->tab[0] < a->tab[2])
	{
		reverse_rotate(*a, 1);
		swap(*a, 1);
	}
	else if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2])
	{
		rotate(*a, 1);
		swap(*a, 1);
	}
	else if (a->tab[0] > a->tab[1] && a->tab[0] > a->tab[2])
		rotate(*a, 1);
	else if (a->tab[1] > a->tab[2])
		reverse_rotate(*a, 1);
	else
		swap(*a, 1);
}

void	ft_tri_rapide(t_itab *a, t_itab *b)
{
	int	min;
	int	min2;

	if (a->size > 3)
	{
		ft_calcul_mins(a, &min, &min2);
		ft_remonter(a, min);
		push(b, a, 1);
		ft_calcul_mins(a, &min, &min2);
		ft_remonter(a, min);
		push(b, a, 1);
		ft_stack_of_3(a);
		push(a, b, 1);
		push(a, b, 1);
	}
	else
		ft_stack_of_3(a);
}
