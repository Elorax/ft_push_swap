/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:27:26 by abiersoh          #+#    #+#             */
/*   Updated: 2022/02/21 19:29:41 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_stack_sorted(t_itab a)
{
	int	i;

	i = 0;
	while (i < a.size - 1)
	{
		if (a.tab[i] > a.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_arg_valid(char *s)
{
	long long int	res;
	int				sign;

	while (*s && (*s == '\f' || *s == '\t'
			|| *s == '\n' || *s == '\r' || *s == '\v' || *s == ' '))
		s++;
	if (!(*s))
		return (0);
	res = 0;
	sign = 1;
	if (s[0] == '-' || s[0] == '+')
	{
		if (*s++ == '-')
			sign = -1;
		if (*s < '0' || *s > '9')
			return (0);
	}
	while ((*s && *s >= '0' && *s <= '9'))
	{
		res = (res * 10) + (*s - '0');
		if (res > 2147483648 || (res > 2147483647 && sign == 1))
			return (0);
		s++;
	}
	/*
	if (*s && (*s > '9' || *s < '0'))
		return (0);
	return (1);
	*/
	return (*s == 0);
}

int	ft_is_stack_valid(t_itab a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < a.size - 1)
	{
		while (j < a.size)
		{
			if (a.tab[i] == a.tab[j])
			{
				return (0);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}
