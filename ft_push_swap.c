/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:27:52 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/29 15:54:13 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_itab	a;
	t_itab	b;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (!ft_init_splitted(argv[1], &a, &b) || !ft_is_stack_valid(a))
			return (write(2, "Error\n", 6), free(a.tab), free(b.tab), 0);
	}
	else
		if (!ft_init_stacks(--argc, &argv[1], &a, &b) || !ft_is_stack_valid(a))
			return (write(2, "Error\n", 6), free(a.tab), free(b.tab), 0);
	if (!ft_is_stack_sorted(a))
	{
		if (a.size < 6)
			ft_tri_rapide(&a, &b);
		else
			ft_tri_stack(&a, &b);
	}
	return (free(a.tab), free(b.tab), 0);
}
