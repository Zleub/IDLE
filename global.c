#include "heros.h"

/* SEMI_DEBUG AREA */

int		ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
	{
		return nbr = ft_putnbr(nbr / 10) - ft_putnbr(nbr % 10);
	}
	nbr += 48;
	write(1, &nbr, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

/* JUSTIFIED */

void	D20(int *base, int size)
{
	int 	nbr;
	int 	i;

	srandom(time(NULL));
	nbr = random();
	nbr = random();
	i = 0;
	while (i < size)
	{
		base[i] = nbr % 21;
		nbr = nbr / 21;
		i = i + 1;
	}
}