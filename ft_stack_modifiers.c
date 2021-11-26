/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:12:38 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/26 13:59:33 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap(t_itab a)
{
	if (a.size > 1)
	{
		ft_swap(&(a.tab[0]), &(a.tab[1]));
	}
	write(1, "s", 1);
	write(1, &(a.pile), 1);
	write(1, "\n", 1);
}

void	push(t_itab *a, t_itab *b)
{
	int	i;

	i = a->size;
	a->size++;
	while (i > 0)
	{
		a->tab[i] = a->tab[i - 1];
		i--;
	}
	a->tab[0] = b->tab[0];
	while (i < b->size - 1)
	{
		b->tab[i] = b->tab[i + 1];
		i++;
	}
	b->tab[i] = 0;
	b->size--;
	write(1, "p", 1);
	write(1, &(a->pile), 1);
	write(1, "\n", 1);
}

void	rotate(t_itab a)
{
	int	i;

	i = 0;
	while (i < a.size - 1)
	{
		ft_swap(&(a.tab[i]), &(a.tab[i + 1]));
		i++;
	}
	write(1, "r", 1);
	write(1, &(a.pile), 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_itab a)
{
	int	i;

	i = a.size - 1;
	while (i > 0)
	{
		ft_swap(&(a.tab[i]), &(a.tab[i - 1]));
		i--;
	}
	write(1, "rr", 2);
	write(1, &(a.pile), 1);
	write(1, "\n", 1);
}
