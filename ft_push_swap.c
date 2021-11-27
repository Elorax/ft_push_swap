/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:27:52 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/27 13:43:19 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_itab	a;
	t_itab	b;

	if (argc < 2)
		return (0);
	else if (!(ft_init_stacks(argc - 1, &argv[1], &a, &b))
		|| (!ft_is_stack_valid(a)))
	{
		write(2, "Error\n", 6);
		free(a.tab);
		free(b.tab);
		return (0);
	}
	else if (!ft_is_stack_sorted(a))
	{
		if (a.size < 6)
			ft_tri_rapide(&a, &b);
		else
			ft_tri_stack(&a, &b);
	}
	free(a.tab);
	free(b.tab);
	return (0);
}
