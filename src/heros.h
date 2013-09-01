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
	int 	level;
	int 	xp;
	int 	life;
	int 	strengh;
	int 	defense;

}				t_heros;

typedef	struct 	s_monster
{
	char	*name;
	int 	life;
	int 	strengh;
	int 	defense;
}				t_monster;

/* file.c */
int		write_file(char *file);
void	open_write_save(t_heros *heros);
void	write_save(t_heros *heros, int filedesc);
t_heros	*open_read_save(t_heros *heros);
t_heros	*read_save(t_heros *heros, char *raw_save);
char	*open_read_monsters(void);
char	*read_monsters(char *buffer);

/* heros.c */
t_monster	*create_monster(t_monster *monster);
void 	print_bright_new(t_heros *bright_new);
void	create_heros(void);

/* global.c */
void	D20(int *base, int size);
int 	ft_strlen(char *str);
int 	ft_strcmp(char *s1, char *s2);
int		ft_putnbr(int nbr);
void	ft_putstr(char *str);
void	itoa(int n, char s[]);
void	reverse(char s[]);

#endif