/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:27:26 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/25 13:28:10 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_is_stack_sorted(t_itab a)
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

int is_arg_valid(char *s)
{
	long long int res;
	int sign;

	while (*s && (*s == '\f' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\v' || *s == ' '))
		s++;
	if (!(*s))
		{printf("419\n");return (0);}
	res = 0;
	sign = 1;
	if (s[0] == '-')
	{	sign = -1;
		s++;}
	if (s[0] == '+')
		s++;
	while (ft_isdigit(*s))
	{
		res = (res * 10) + (*s - '0');
		s++;
	}
	res = res * sign;
	if (*s && !ft_isdigit(*s))
		return (0);
	if (res > 2147483647 || res < -2147483648)
		return (0);
	return (1);
}

int ft_is_stack_valid(t_itab a)
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
				printf("%d et %d\n\n", i, j);
				return (0);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}
