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
//	if (enter == 'L' || enter == 'l')
//		load_game();
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