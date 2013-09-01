#include "heros.h"

t_monster	*create_monster(t_monster *monster)
{
	int array_D20[2];

	D20(&array_D20[0], 2);
	monster->name = open_read_monsters();
	monster->life = 20;
	monster->strengh = array_D20[0];
	monster->defense = array_D20[1];
	return (monster);
}

void 	print_bright_new(t_heros *bright_new)
{
	ft_putstr(bright_new->name);
	write (1, " [", 2);
	ft_putnbr(bright_new->level);
	write (1, "][", 2);
	ft_putnbr(bright_new->xp);
	write (1, "]", 1);
	write (1, " created with strengh = ", 24);
	ft_putnbr(bright_new->strengh);
	write (1, ", defense = ", 12);
	ft_putnbr(bright_new->defense);
	write (1, " and ", 5);
	ft_putnbr(bright_new->life);
	write (1, " life", 5);
	write (1, "\n", 1);
}

void	create_heros(void)
{
	t_heros	*bright_new;
	int array_D20[2];
	int i;

	D20(&array_D20[0], 2);
	i = 0;
	bright_new = malloc (sizeof(t_heros));
	bright_new->name = malloc (sizeof(bright_new->name) * 20 + 1);
	write (1, "Entrez un nouveau nom : ", 24);
	bright_new->name = fgets(bright_new->name, 20, fdopen(0, "r"));
	while (bright_new->name[i] != 10)
		i++;
	bright_new->name[i] = '\0';
	bright_new->strengh = array_D20[0];
	bright_new->defense = array_D20[1];
	bright_new->level = 1;
	bright_new->xp = 0;
	bright_new->life = 20;
	print_bright_new(bright_new);
	open_write_save(bright_new);
}