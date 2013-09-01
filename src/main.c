#include "heros.h"

void	new_game(void)
{
	int 	enter;

	create_heros();
	write(1, "Inizialitazion - Press Enter", 28);
	enter = fgetc(fdopen(0, "r"));
	if (enter == 10)
		return ;
}

void	play_round(t_heros *heros)
{
	t_monster *monster;
	int 	enter;

	write (1, "auto-battling\n", 15);
	monster = malloc(sizeof(t_monster));
	monster = create_monster(monster);
	ft_putstr(heros->name);
	write (1, " [", 2);
	ft_putnbr(heros->level);
	write (1, "][", 2);
	ft_putnbr(heros->xp);
	write (1, "] encounters a ", 15);
	ft_putstr(monster->name);
	write (1, "\n", 1);
	free (monster);
	write(1, "Press Enter", 11);
	enter = fgetc(fdopen(0, "r"));
	if (enter == 10)
		play_round(heros);
}


void	load_game(void)
{
	t_heros *heros;

	heros = malloc(sizeof(t_heros));
	heros = open_read_save(heros);
	if (heros->name)
	{
		write (1, "Load done !\n", 13);
		play_round(heros);
	}
}

void	menu(void)
{
	int 	enter;

	write(1, "Bonjour, veuillez choisir une option\n", 38);
	write(1, "(N)ew game\n", 12);
	write(1, "(L)oad game\n", 13);
	write(1, "(R)egles\n", 9);
	write(1, "(E)xit\n", 8);
	enter = fgetc(fdopen(0, "r"));
	if (enter == 'N' || enter == 'n')
		new_game();
	if (enter == 'L' || enter == 'l')
		load_game();
//	if (enter == 'R' || enter == 'r')
//		write_file("");
	if (enter == 'E' || enter == 'e')
		return ;
	write(1, "\n", 1);
	menu();
}

int 	main(void)
{
	menu();
	return(0);
}