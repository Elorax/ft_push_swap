/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:23:12 by abiersoh          #+#    #+#             */
/*   Updated: 2022/05/07 15:25:18 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	calcul_nb_parsing(int size)
{
	if (size <= 100)
		return (4);
	if (size <= 600)
		return (9);
	if (size <= 1000)
		return (20);
	return (25);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	*find_parsing(t_itab a)
{
	int	*tab;
	int	i;
	int	*tab2;

	tab = (int *) malloc(sizeof(int) * (calcul_nb_parsing(a.size) + 2));
	if (!tab)
		return (NULL);
	tab[0] = calcul_nb_parsing(a.size);
	tab2 = malloc(a.size * sizeof(int));
	if (!tab2)
		return ((free(tab), NULL));
	i = -1;
	while (++i < a.size)
		tab2[i] = a.tab[i];
	tri_tableau(tab2, a.size);
	tab[1] = tab2[a.size - 1];
	tab[calcul_nb_parsing(a.size) + 1] = tab2[0];
	i = 0;
	while (++i < calcul_nb_parsing(a.size))
		tab[i + 1] = tab2[max(0,
				(a.size - 1) - (i * (a.size / calcul_nb_parsing(a.size))))];
	free(tab2);
	return (tab);
}

void	tri_tableau(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(tab + i, tab + j);
			j++;
		}
		i++;
	}
}
