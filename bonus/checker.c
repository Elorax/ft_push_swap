/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:47:13 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/06 23:47:52 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include "get_next_line.h"

void	check_str(t_itab *a, t_itab *b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap(*a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap(*b, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		(swap(*a, 0), swap(*b, 0));
	else if (!ft_strncmp(str, "pa\n", 3))
		push(a, b, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		push(b, a, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate(*a, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate(*b, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		(rotate(*a, 0), rotate(*b, 0));
	else if (!ft_strncmp(str, "rrr\n", 4))
		(reverse_rotate(*b, 0), reverse_rotate(*a, 0));
	else if (!ft_strncmp(str, "rra\n", 4))
		reverse_rotate(*a, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		reverse_rotate(*b, 0);
	else
		exit(free(str), write(1, "Error\n", 6), EXIT_SUCCESS);
	str = (free(str), get_next_line(0));
}

void	checker(t_itab *a, t_itab *b)
{
	char	*str;

	str = get_next_line(0);
	if (ft_is_stack_sorted(a) && (str != NULL))
		write(1, "KO\n", 3);
	while (str != NULL)
		check_str(a, b, str);
}

int	main(int ac, char **av)
{
	t_itab	a;
	t_itab	b;
	char	*str;

	if (!ft_init_stacks(ac - 1, &av[1], &a, &b) || !ft_is_stack_valid(a))
		return (write(1, "Error\n", 6), free(a.tab), free(b.tab), 0);
	checker(&a, &b);
	if (ft_is_stack_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a.tab);
	free(b.tab);
}
