#ifndef HEROS_H
 #define HEROS_H
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

typedef	struct	s_heros
{
	char	*name;
	int 	strengh;
	int 	defense;

}				t_heros;

/* file.c */
void	write_save(t_heros heros, int filedesc);
void	open_write_save(t_heros heros);
int		write_file(char *file);
t_heros	open_read_save(t_heros heros);

/* heros.c */
void	create_heros(void);

/* global.c */
void	D20(int *base, int size);
int ft_strlen(char *str);
int		ft_putnbr(int nbr);
void	ft_putstr(char *str);
void itoa(int n, char s[]);
void reverse(char s[]);

#endif