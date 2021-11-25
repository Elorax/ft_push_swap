#include <unistd.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	cpy;

	cpy = n * (1 - (2 * (n < 0)));
	write(fd, "-", n < 0);
	if (cpy > 9)
		ft_putnbr_fd(cpy / 10, fd);
	ft_putchar_fd(cpy % 10 + '0', fd);
}
