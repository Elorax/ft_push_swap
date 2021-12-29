/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:57:20 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/29 14:15:35 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include "libft/libft.h"

typedef struct s_itab
{
	int		*tab;
	int		size;
	char	pile;
}	t_itab;

/*	Echange tout simplement les deux valeurs pointees par a et b	*/
void	ft_swap(int *a, int *b);

/*	Free tous les *s puis s											*/
void	ft_freesplit(char **s);
/*	Swap first and second element of a stack						*/
void	swap(t_itab a, int display);
/*	Push first element of stack a to the top of stack b				*/
void	push(t_itab *a, t_itab *b, int display);
/*	Rotates the stack a to the top. first element becomes last one	*/
void	rotate(t_itab a, int display);
/*	Reverse rotates the stack. Last element becomes first one		*/
void	reverse_rotate(t_itab a, int display);
/*	Check if an argument is numeric and in the integer range		*/
int		is_arg_valid(char *s);
/*	Execute the amount of rotate or reverse_rotate needed to put	*/
/*	the desired element to the top of the stack						*/
void	ft_remonter(t_itab *a, int index);
/*	Initialize stack a with the nb value contained in **av			*/
int		ft_init_stacks(int nb, char **av, t_itab *a, t_itab *b);
/*	Initialize stack a with values in av[1]							*/
int		ft_init_splitted(char *av, t_itab *a, t_itab *b);
/*	Display the current states of the stacks a and b				*/
void	ft_display_stacks(t_itab a, t_itab b);
/*	Fast sort for stacks of 2 or 3 elements							*/
void	ft_stack_of_3(t_itab *a);
/*	Find the indexes of the lowest and highest integer in a stack	*/
void	ft_calcul_mins(t_itab *a, int *min, int *max);
/*	Fast sort for stacks of 5 or less								*/
void	ft_tri_rapide(t_itab *a, t_itab *b);
/*	find which value will be the fastest to climb the top of stacks */
int		ft_find_closest(int a, int b, int size);

//void	ft_remonter(t_itab *a, int index);

/*	Returns the number of chunks we should use in our sort method	*/
int		calcul_nb_pasring(int size);
/*	push every element of b in a, in a sorted order					*/
void	ft_push_stack(t_itab *a, t_itab *b);
/*	fill an integer array with the minimum and maximum values of	*/
/*	each chunk														*/
int		*find_parsing(t_itab a);
/*	rotates a until every value of the current chunk has been pushed*/
/*	in stack b														*/
void	ft_chunk_to_stack(t_itab *a, t_itab *b, int *parsing, int idx_pars);
/*	main algorithm in which the stack a is sorted					*/
void	ft_tri_stack(t_itab *a, t_itab *b);
/*	Checks if the values in entry of the programm are already sorted*/
int		ft_is_stack_sorted(t_itab a);
/*	Checks if the stack initialized is valid, if there is			*/
/*	no duplicated values											*/
int		ft_is_stack_valid(t_itab a);

#endif
