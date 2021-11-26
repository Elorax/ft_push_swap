/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:15:31 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/26 13:37:16 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_init_stacks(int nb, char **av, t_itab *a, t_itab *b)
{
	int	i;	

	a->tab = (int *) malloc (sizeof(int) * (nb));
	if (!(a->tab))
		return (0);
	b->tab = (int *) malloc (sizeof(int) * (nb));
	if (!(b->tab))
	{
		free(a->tab);
		return (0);
	}
	a->size = nb;
	b->size = 0;
	a->pile = 'a';
	b->pile = 'b';
	i = 0;
	while (av[i])
	{
		a->tab[i] = atoi(av[i]);
		if (!is_arg_valid(av[i]))
			return (0);
		i++;
	}
	return (1);
}
