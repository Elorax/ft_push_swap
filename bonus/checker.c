#include "../ft_push_swap.h"
#include "get_next_line.h"

void	checker(t_itab *a, t_itab *b)
{
	char	*str;
	while ((str = get_next_line(0)) != NULL)
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
		/*else
		{
			free(str);
			write(2, "Wrong output", 7);
			return ;
		}*/
		free(str);
	}
}

int main(int ac, char **av)
{
	t_itab a;
	t_itab b;

	char	*str;
	char	*str2;
	if (ac < 2)
	{
		str = get_next_line(1);
		str2 = get_next_line(2);
		if (str || str2)
		{
			printf("KO arg < 2\n");
			//free(str);
			//free(str2);
			return (0);
		}
		else
		{
			printf("OK arg < 2\n");
			return (0);
		}
	}
	else if (!ft_init_stacks(ac - 1, &av[1], &a, &b) || !ft_is_stack_valid(a))
	{
		str = get_next_line(2);
		if(!ft_strncmp(str, "Error\n", 6))
		{
			printf("OK error bien ecrite\n");
			//free(str);
			return 0;
		}
		else
		{
			printf("KO pas derreur ecrite\n");
			//free(str);
			return 0;
		}
	}
	else if (ft_is_stack_sorted(a))
	{
		str = get_next_line(1);
		if(!str)
		{
			printf("OK champ vide\n");
		}
		else
		{
			printf("KO champ non vide\n");
			//free(str);
			return 0;
		}
	}
	checker(&a, &b);
	if (ft_is_stack_sorted(a))
	{
		printf("OK bien trie\n");
		//free(a.tab);
		//free(b.tab);
		return 0;
	}
	else
	{
		printf("KO mal triee\n");
		//free(a.tab);
		//free(b.tab);
		return 0;
	}
}
