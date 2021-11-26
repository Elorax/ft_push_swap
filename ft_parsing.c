/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:23:12 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/26 12:15:39 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	calcul_nb_parsing(int size)
{
	if (size <= 10)
		return (1);
	if (size <= 20)
		return (2);
	if (size <= 100)
		return (5);
	if (size <= 200)
		return (6);
	if (size <= 300)
		return (8);
	if (size <= 400)
		return (10);
	if (size <= 600)
		return (11);
	return (12);
}

int	*find_parsing(t_itab a)
{
	int	*parse;
	int	i;
	int	count_parse;
	int	nb_parsing;
	int	j;

	nb_parsing = calcul_nb_parsing(a.size);

	parse = (int *) malloc(sizeof(int) * (nb_parsing + 2));
	if (!parse)
		return (NULL);
	parse[0] = nb_parsing;
	i = 0;
	while (i < a.size)
	{
		j = 0;
		count_parse = 0;
		while (j < a.size)
		{
			if (a.tab[i] <= a.tab[j])
				count_parse++;
			j++;
		}
		//Si count_parse est divisible par la taille d'un chunk
		if (!(count_parse % (a.size/parse[0])))
		{
		//Alors on rentre ce nombre dans la taille du chunk. Peutetre a reecrire plus tard
			parse[1 + (count_parse/(a.size/parse[0]))] = a.tab[i];
			//parse[parse[0] - count_parse/(a.size/parse[0])] = a.tab[i];
		}
		if (count_parse == 1)
			parse[1] = a.tab[i];
		if (count_parse == a.size)
			parse[parse[0] + 1] = a.tab[i];
		i++;
	}
	return (parse);
}
