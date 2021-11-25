/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:17:01 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/25 13:17:05 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_display_stacks(t_itab a, t_itab b)
{
	int	i;

	i = 0;
	while (i < a.size || i < b.size)
	{
		if (i < a.size)
		{
			ft_putnbr_fd(a.tab[i], 1);
		}
		else
		{
			write(1, " ", 2);
		}
		write (1, "  ", 2);
		if (i < b.size)
		{
			ft_putnbr_fd(b.tab[i], 1);
		}
		write(1, "\n", 1);
		i++;
	}
	write (1, "__  __\na   b\n", 13);
}
