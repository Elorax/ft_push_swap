#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int doublons(int *tab, int size)
{
	int	i = 0;
	int	j = 0;

	while (i < size - 1)
	{
		while (++j < size)
			if (tab[i] == tab[j])
				return (1);
		j = ++i;
	}
	return (0);
}

int main(int ac, char **av)
{
	int	*tab;

	if (ac < 2)
		return (0);
	srand(time(NULL));
	int size = atoi(av[1]);
	tab = malloc(sizeof(int) * size);
	int	i = 0;

	while (i < size)
	{
		tab[i] = (rand() % 1000) - 500;
		if (!(doublons(tab, i + 1)))
			i++;
	}
	for(i = 0; i < size; i++)
		printf("%d ", tab[i]);
	free(tab);
	return (0);
}
