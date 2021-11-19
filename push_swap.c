#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"


#define sa(); swap(a);
#define sb(); swap(b);
#define ss(); sa();sb();
#define pa(); push(a, b);
#define pb(); push(b, a);
#define ra(); rotate(a);
#define rb(); rotate(b);
#define rr(); ra();rb();
#define rra(); reverse_rotate(a);
#define rrb(); reverse_rotate(b);
#define rrr(); rra();rrb();

void	ft_swap(int *a, int *b)
{
	int	tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

typedef struct	s_itab
{
	int	*tab;
	int	size;
}	t_itab;

void	swap(t_itab a);
void	push(t_itab a, t_itab b);
void	rotate(t_itab a);
void	reverse_rotate(t_itab a);


void	swap(t_itab a)
{
	if (a.size > 1)
	{
		ft_swap(&(a.tab[0]), &(a.tab[1]));
	}
}

void push(t_itab a, t_itab b)
{
	int	i;

	i = a.size;
	a.size++;
	while (i > 0)
	{
		a.tab[i] = a.tab[i - 1];
		i--;
	}
	a.tab[0] = b.tab[0];
	while (i < b.size - 1)
	{
		b.tab[i] = b.tab[i + 1];
		i++;
	}
	b.tab[i] = 0;
	b.size--;
}

void	rotate(t_itab a)
{
	int	i;

	i = 0;
	while (i < a.size - 1)
	{
		ft_swap(&(a.tab[i]), &(a.tab[i + 1]));
		i++;
	}
}

void	reverse_rotate(t_itab a)
{
	int	i;

	i = a.size - 1;
	while (i > 0)
	{
		ft_swap(&(a.tab[i]), &(a.tab[i - 1]));
		i--;
	}
}

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
			write(1, "  ", 2);
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
void	ft_init_stacks(int nb, char **av, t_itab *a, t_itab *b)
{
	int	i;	

	a->tab = (int *) malloc (sizeof(int) * (nb));
	if (!(a->tab))
		return ;
	b->tab = (int *) malloc (sizeof(int) * (nb));
	if (!(b->tab))
	{
		free(a->tab);
		return ;
	}
	a->size = nb;
	b->size = 0;
	i = 0;
	while (av[i])
	{
		a->tab[i] = ft_atoi(av[i]);
		i++;
	}
}
int main(int argc, char **argv)
{
	t_itab	a;
	t_itab	b;

	if (argc < 2)
	{
		printf("Pas de pile a trier.\n");
		return (0);
	}
	ft_init_stacks(argc - 1, &argv[1], &a, &b);
	ft_display_stacks(a, b);
	sa();
	ft_display_stacks(a, b);
	free(a.tab);
	free(b.tab);
	return (0);
}
