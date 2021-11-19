#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"


#define sa(); swap(a);
#define sb(); swap(b);
#define ss(); sa();sb();
#define pa(); push(&a, &b);
#define pb(); push(&b, &a);
#define ra(); rotate(a);
#define rb(); rotate(b);
#define rr(); ra();rb();
#define rra(); reverse_rotate(a);
#define rrb(); reverse_rotate(b);
#define rrr(); rra();rrb();
int	counter;

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
	char	pile;
}	t_itab;

void	swap(t_itab a);
void	push(t_itab *a, t_itab *b);
void	rotate(t_itab a);
void	reverse_rotate(t_itab a);


void	swap(t_itab a)
{
	counter++;
	if (a.size > 1)
	{
		ft_swap(&(a.tab[0]), &(a.tab[1]));
	}
	write(1, "s", 1);
	write(1, &(a.pile), 1);
	write(1, "\n", 1);
}

void push(t_itab *a, t_itab *b)
{
	int	i;
	counter++;

	i = a->size;
	a->size++;
	while (i > 0)
	{
		a->tab[i] = a->tab[i - 1];
		i--;
	}
	a->tab[0] = b->tab[0];
	while (i < b->size - 1)
	{
		b->tab[i] = b->tab[i + 1];
		i++;
	}
	b->tab[i] = 0;
	b->size--;
	write(1, "p", 1);
	write(1, &(a->pile), 1);
	write(1, "\n", 1);
}

void	rotate(t_itab a)
{
	int	i;
	counter++;
	i = 0;
	while (i < a.size - 1)
	{
		ft_swap(&(a.tab[i]), &(a.tab[i + 1]));
		i++;
	}
	write(1, "r", 1);
	write(1, &(a.pile), 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_itab a)
{
	int	i;
	counter++;
	i = a.size - 1;
	while (i > 0)
	{
		ft_swap(&(a.tab[i]), &(a.tab[i - 1]));
		i--;
	}
	write(1, "rr", 2);
	write(1, &(a.pile), 1);
	write(1, "\n", 1);
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
	a->pile = 'a';
	b->pile = 'b';
	i = 0;
	while (av[i])
	{
		a->tab[i] = ft_atoi(av[i]);
		i++;
	}
}

void	ft_stack_of_3(t_itab *a)
{
	if (a->size == 2)
	{
		if (a->tab[0] > a->tab[1])
		swap(*a);
	}
	else if (a->tab[0] < a->tab[1] && a->tab[1] < a->tab[2])
		return ;
	else if (a->tab[0] < a->tab[1] && a->tab[0] < a->tab[2])
	{
		reverse_rotate(*a);
		swap(*a);
	}
	else if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2])
	{
		rotate(*a);
		swap(*a);
	}
	else if (a->tab[0] > a->tab[1] && a->tab[0] > a->tab[2])
		rotate(*a);
	else if (a->tab[1] > a->tab[2])
		reverse_rotate(*a);
	else
		swap(*a);
}

int	ft_find_closest(int a, int b, int size)
{
	if (size == 4)
		return (a);
	if ((a < (size - b) && a < b) || ((size - a) < (size - b) && (size - a) < a))
		return (a);
	else
		return (b);
}

void	ft_remonter(t_itab *a, int indice)
{
	int	i;

	i = indice;
	if (i <= a->size / 2)
	{
		while (i)
		{
			rotate(*a);
			i--;
		}
	}
	else
		while (i < a->size)
		{
			reverse_rotate(*a);
			i++;
		}
	/*printf("Apres remontee :\n\n");
	ft_display_stacks(*a, *b);*/
}

void	ft_tri_stack(t_itab *a, t_itab *b)
{
	int	i;
	int	min;
	int	min2;
	int triche;

	triche = 0;
	while (a->size > 3)
	{
		i = 2;
		min = (a->tab[0] > a->tab[1]);
		min2 = !(min);
		while (i < a->size)
		{
			if (a->tab[min] > a->tab[i])
			{
				min2 = min;
				min = i;
			}
			else if (a->tab[min2] > a->tab[i])
				min2 = i;
			i++;
		}
		//printf("indices minimaux : %d(%d), %d(%d)\n\n\n", min, a->tab[min], min2, a->tab[min2]);
		//min = ft_find_closest(min, min2, a->size);
		if (triche)
		{
			ft_remonter(a, min);
			//printf("Je viens de tricher !\n\n");
			triche = 0;
		}
		else
		{
			triche = min - ft_find_closest(min, min2, a->size);
			ft_remonter(a, ft_find_closest(min, min2, a->size));
		}
		push(b, a);
		//printf("Apres push :\n\n");
		//ft_display_stacks(*a, *b);
		if ((b->size >= 2) && (b->tab[0] < b->tab[1]))
		{
			swap(*b);
			//printf("Apres swap : \n\n");
			//ft_display_stacks(*a, *b);
		}
	}
	ft_stack_of_3(a);
	//printf("Apres tri des trois elements de a : \n\n");
	//printf("b->size vaut %d\n\n", b->size);
	//ft_display_stacks(*a, *b);
	while (b->size)
	{
		push(a, b);
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
	write(1, "\n\nResolution...\n\n\n", 18);
	ft_tri_stack(&a, &b);
	printf("\n\n");
	ft_display_stacks(a, b);
	free(a.tab);
	free(b.tab);
	printf("Nb d'operations : %d\n", counter);
	return (0);
}
