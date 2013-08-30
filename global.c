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

/* TO DO AGAIN */

void reverse(char s[])
{
    int i;
    int j;
    char c;

    for (i = 0, j = ft_strlen(s)-1; i<j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* JUSTIFIED */

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

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