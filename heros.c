#include "heros.h"

 void	create_heros(void)
{
	t_heros	bright_new;
	int array_D20[2];
	int i;

	D20(&array_D20[0], 2);
	i = 0;
	bright_new.name = (char *) malloc (sizeof(bright_new.name) * 20 + 1);
	write (1, "Entrez un nouveau nom : ", 24);
	bright_new.name = fgets(bright_new.name, 20, fdopen(0, "r"));
	while (bright_new.name[i] != 10)
		i++;
	bright_new.name[i] = '\0';
	bright_new.strengh = array_D20[0];
	bright_new.defense = array_D20[1];
	ft_putstr(bright_new.name);
	write (1, " created with strengh = ", 24);
	ft_putnbr(bright_new.strengh);
	write (1, " & defense = ", 13);
	ft_putnbr(bright_new.defense);
	write (1, "\n", 1);
	open_write_save(bright_new);
}