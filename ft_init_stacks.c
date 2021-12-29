/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:15:31 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/29 15:54:54 by abiersoh         ###   ########.fr       */
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
		a->tab[i] = ft_atoi(av[i]);
		if (!is_arg_valid(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_init_splitted(char *av, t_itab *a, t_itab *b)
{
	int		i;
	char	**tmp;

	tmp = ft_split(av, ' ');
	i = 0;
	while (tmp[i])
		i++;
	a->tab = (int *) malloc (sizeof(int) * i);
	if (!a->tab)
		return (ft_freesplit(tmp), (b->tab = NULL), 0);
	b->tab = (int *) malloc (sizeof(int) * i);
	if (!b->tab)
		return (ft_freesplit(tmp), free(a->tab), (a->tab = NULL), 0);
	a->size = i;
	b->size = 0;
	a->pile = 'a';
	b->pile = 'b';
	i = -1;
	while (tmp[++i])
	{
		a->tab[i] = ft_atoi(tmp[i]);
		if (!is_arg_valid(tmp[i]))
			return (ft_freesplit(tmp), 0);
	}
	return (ft_freesplit(tmp), 1);
}
