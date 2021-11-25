#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"


/*#define sa(); swap(a);
#define sb(); swap(b);
#define ss(); sa();sb();
#define pa(); push(&a, &b);
#define pb(); push(&b, &a);
#define ra(); rotate(a);
#define rb(); rotate(b);
#define rr(); ra();rb();
#define rra(); reverse_rotate(a);
#define rrb(); reverse_rotate(b);
#define rrr(); rra();rrb();*/


/*A modifier : Variable globale pour compter le nombre d'appels.*/
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
int		is_arg_valid(char *s);
void	ft_remonter(t_itab *a, int indice);


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

int		ft_init_stacks(int nb, char **av, t_itab *a, t_itab *b)
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
		a->tab[i] = atoi(av[i]);
		if (!is_arg_valid(av[i]))
	{printf("%s n'est pas valide\n", av[i]);
			return (0);}
		i++;
	}
	return (1);
}


/* Jusqu'ici : Rien besoin de modifier.*/




//Peut etre a ameliorer

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

void	ft_calcul_mins(t_itab *a, int *min, int *min2)
{

	int i;

	i = 0;
	*min = (a->tab[0] > a->tab[1]);
	*min2 = !(*min);
	while (i < a->size)
	{
		if (a->tab[*min] > a->tab[i])
		{
			*min2 = *min;
			*min = i;
		}
		else if (a->tab[*min2] > a->tab[i])
			*min2 = i;
		i++;
	}
}

void	ft_tri_rapide(t_itab *a, t_itab *b)
{
	int min;
	int min2;
	int i;

	if (a->size > 3)
	{
		ft_calcul_mins(a, &min, &min2);
		printf("min et min2 %d %d\n", a->tab[min], a->tab[min2]);
		ft_remonter(a, min);
		push(b, a);
		ft_calcul_mins(a, &min, &min2);
		ft_remonter(a, min);
		push(b, a);
		ft_stack_of_3(a);
		push(a, b);
		push(a, b);
	}
	else
		ft_stack_of_3(a);
}
//Ca en theorie ca marche pas trop mal, faut voir si condition de taille ou pas

int	ft_find_closest(int a, int b, int size)
{
	/*if (size == 4)
		return (a);*/
	if ((a < (size - b) && a < b) || ((size - a) < (size - b) && (size - a) < a))
		return (a);
	else
		return (b);
}

//Ca en theorie ca marche pas trop mal

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
}



/*
|
|Bon bah a partir de la y a du boulot	|
										|
										*/

int	calcul_nb_parsing(int size)
{
	if (size <= 20)
		return (1);
	if (size <= 40)
		return (2);
	if (size <= 70)
		return (3);
	if (size <= 100)
		return (4);
	if (size <= 200)
		return (6);
	if (size <= 350)
		return (8);
	if (size <= 550)
		return (10);
	return (size/50);
}

int	*find_parsing(t_itab a)
{
	int	*parse;
	int	i;
	int	count_parse;
	int	nb_parsing;
	int	j;

	nb_parsing = calcul_nb_parsing(a.size);

	parse = (int *) malloc(sizeof(int) * (nb_parsing + 2));
	if (!parse)
		return (NULL);
	parse[0] = nb_parsing;
	i = 0;
	while (i < a.size)
	{
		j = 0;
		count_parse = 0;
		while (j < a.size)
		{
			if (a.tab[i] <= a.tab[j])
				count_parse++;
			j++;
		}
		//Si count_parse est divisible par la taille d'un chunk
		if (!(count_parse % (a.size/parse[0])))
		{
		//Alors on rentre ce nombre dans la taille du chunk. Peutetre a reecrire plus tard
			parse[1 + (count_parse/(a.size/parse[0]))] = a.tab[i];
			//parse[parse[0] - count_parse/(a.size/parse[0])] = a.tab[i];
		}
		if (count_parse == 1)
			parse[1] = a.tab[i];
		if (count_parse == a.size)
			parse[parse[0] + 1] = a.tab[i];
		i++;
	}
	//return (parse);

	/*int	test;
	test = 0;
	while (test < parse[0])
	{
		printf("%d, ", parse[test]);
		test++;
	}*/
	return (parse);
}

void	ft_tri_stack(t_itab *a, t_itab *b)
{
	int	i;
	int	min;
	int	max;
	int	*parsing;
	int	j;
	int idx_pars;
	int	size;

	idx_pars = 2;
	parsing = find_parsing(*a);
	i = 0;
	size = a->size;
	//Boucle pour faire le tour de a et push dans b.
	while (idx_pars < parsing[0] + 2)
	{
		i = 0;
		size = a->size;
		//printf("Parsing : Tant que i < %d ou a->tab[0] <= %d\n\n", size, parsing[idx_pars - 1]);
		while (i < size && a->tab[0] <= parsing[idx_pars - 1])
		{
			//Deuxieme condition probablement inutile dans le while ou dans le if (surement le if)
			//printf("Si a->tab[0] >= a %d et que a->tab[0] <= a %d\nalors on pb sinon on ra\n\n", parsing[idx_pars], parsing[idx_pars - 1]);
			if (a->tab[0] >= parsing[idx_pars] && a->tab[0] <= parsing[idx_pars - 1])
				push(b, a);
			else
				rotate(*a);
			i++;
		}
		size = b->size;
		i = 0;
			//printf("Maintenant, tant que i < b->size, on trouve le min/max et on le pa into ra si necessaire\n\n");
		//Boucle pour ranger b dans a. Ici osef du parsing ?
		while (i < size)
		{
			min = 0;
			max = 0;
			//Trouvage du minimum/maximum.
			j = 0;
			//printf("Etape numero %d du rangement : \n", i);
			while (j < b->size)
			{
				if (b->tab[min] > b->tab[j])
					min = j;
				if (b->tab[max] < b->tab[j])
					max = j;
				j++;
			}
			//ft_display_stacks(*a, *b);
			ft_remonter(b, ft_find_closest(min, max, b->size));
			//ft_display_stacks(*a, *b);
			push(a, b);
			//Si on vient de push le minimum ou le maximum, rotate ou non a faire.
			if (ft_find_closest(min, max, b->size + 1) == min)
				rotate(*a);
			//ft_display_stacks(*a, *b);
			i++;
		}
		//On rotate toute la partie triee et on revient au debut de ce qui reste a trier.
		while (a->tab[0] > parsing[idx_pars])
			rotate(*a);
		//printf("Etat apres premier parsing, pret pour pb : \n\n");
		//ft_display_stacks(*a, *b);
		idx_pars++;
	}
	free(parsing);
}

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



/*int main(int argc, char **argv)
{
	t_itab	a;
	t_itab	b;

	if (argc < 2)
	{
		printf("Pas de pile a trier.\n");
		return (0);
	}
	if (!(ft_init_stacks(argc - 1, &argv[1], &a, &b)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_display_stacks(a, b);
	if (!(ft_is_stack_valid(a)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!ft_is_stack_sorted(a))
	{
		write(1, "\n\nResolution...\n\n\n", 18);
		if (a.size < 6)
		{
			ft_tri_rapide(&a, &b);
		}
		else
			ft_tri_stack(&a, &b);
		printf("\n\n");
		ft_display_stacks(a, b);
	}
	else
		write(1, "C'est deja sorted patate\n", 25);
	free(a.tab);
	free(b.tab);
	printf("Nb d'operations : %d\n", counter);
	return (0);
}*/


int main(int argc, char **argv)
{
	t_itab	a;
	t_itab	b;

	if (argc < 2)
		return (0);
	else if (!(ft_init_stacks(argc - 1, &argv[1], &a, &b)))
	{
		write(2, "Error\n", 6);
		free(a.tab);
		free(b.tab);
		return (0);
	}
	else if (!(ft_is_stack_valid(a)))
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
	else
		write(1, "C'est deja sorted patate\n", 25);
	ft_display_stacks(a, b);
	free(a.tab);
	free(b.tab);
	printf("Nb d'operations : %d\n", counter);
	return (0);
}
