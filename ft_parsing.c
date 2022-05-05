/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:23:12 by abiersoh          #+#    #+#             */
/*   Updated: 2022/05/05 18:08:32 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	calcul_nb_parsing(int size)
{
	if (size <= 100)
		return (5);
	if (size <= 600)
		return (10);
	if (size <= 1000)
		return (20);
	return (25);
}

int	*find_parsing(t_itab a)
{
	int	*parse;
	int	i;
	int	count_parse;
	int	j;

	parse = (int *) malloc(sizeof(int) * (calcul_nb_parsing(a.size) + 2));
	if (!parse)
		return (NULL);
	parse[0] = calcul_nb_parsing(a.size);
	i = -1;
	while (++i < a.size)
	{
		j = -1;
		count_parse = 0;
		while (++j < a.size)
			if (a.tab[i] <= a.tab[j])
				count_parse++;
		if (!(count_parse % (a.size / parse[0])))
			parse[1 + (count_parse / (a.size / parse[0]))] = a.tab[i];
		if (count_parse == 1)
			parse[1] = a.tab[i];
		if (count_parse == a.size)
			parse[parse[0] + 1] = a.tab[i];
	}
	return (parse);
}
