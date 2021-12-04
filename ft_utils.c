/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:27:52 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/26 14:04:23 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_calcul_mins(t_itab *a, int *min, int *min2)
{
	int	i;

	i = 0;
	*min = (a->tab[0] > a->tab[1]);
	*min2 = !(*min);
	while (i < a->size)
	{
		if (a->tab[*min] > a->tab[i])
		{
			*min2 = *min;
			*min = i;
		}
		else if (a->tab[*min2] > a->tab[i])
			*min2 = i;
		i++;
	}
}

int	ft_find_closest(int a, int b, int size)
{
	if ((a < (size - b) && a < b)
		|| ((size - a) < (size - b) && (size - a) < a))
		return (a);
	else
		return (b);
}

void	ft_remonter(t_itab *a, int indice)
{
	int	i;

	i = indice;
	if (i <= a->size / 2)
	{
		while (i)
		{
			rotate(*a, 1);
			i--;
		}
	}
	else
	{
		while (i < a->size)
		{
			reverse_rotate(*a, 1);
			i++;
		}
	}
}
