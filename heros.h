#ifndef HEROS_H
 #define HEROS_H
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

/* file.c */
int		write_file(char *file);

/* heros.c */
void	create_heros(void);

/* global.c */
void	D20(int *base, int size);
int		ft_putnbr(int nbr);
void	ft_putstr(char *str);

typedef	struct	s_heros
{
	char	*name;
	int 	strengh;
	int 	defense;

}				t_heros;

#endif