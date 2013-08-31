#include "heros.h"

void	write_save(t_heros *heros, int filedesc)
{
	char	tmp[20];

//	write (filedesc, "heros.name : ", 13);
	write (filedesc, heros->name, ft_strlen(heros->name));
	write (filedesc, "\n", 1);
	itoa(heros->strengh, tmp);
//	write (filedesc, "heros.strengh : ", 16);
	write (filedesc, tmp, ft_strlen(tmp));
	write (filedesc, "\n", 1);
	itoa(heros->defense, tmp);
//	write (filedesc, "heros.defense : ", 16);
	write (filedesc, tmp, ft_strlen(tmp));
	write (filedesc, "\n", 1);
}

void	open_write_save(t_heros *heros)
{
	int filedesc;

	filedesc = open("./save.txt", O_WRONLY | O_TRUNC | O_CREAT , S_IRWXU);
	if (filedesc == -1)
	{
		write(2, "Open() failed\n", 14);
	}
	write_save(heros, filedesc);
	close(filedesc);
}

t_heros	*read_save(t_heros *heros, char *raw_save)
{
	int 	cmp[5];
	char	data[100][100];

	cmp[0] = 0;
	cmp[1] = 0;
	while (raw_save[cmp[0]] != '\0')
	{
		cmp[2] = 0;
		while (raw_save[cmp[0]] != 10)
		{
			data[cmp[1]][cmp[2]] = raw_save[cmp[0]];
			cmp[0] = cmp[0] + 1;
			cmp[2] = cmp[2] + 1;
		}
		data[cmp[1]][cmp[2]] = '\0';
		cmp[0] = cmp[0] + 1;
		cmp[1] = cmp[1] + 1;
	}
	heros->name = data[0];
	heros->strengh = atoi(data[1]);
	heros->defense = atoi(data[2]);
	return (heros);
}

t_heros	*open_read_save(t_heros *heros)
{
	int 	filedesc;
	int 	nb;
	char	buffer[1000];

	filedesc = open("./save.txt", O_RDONLY);
	if (filedesc == -1)
	{
		write(2, "Open() failed\n", 14);
	}
	nb = read(filedesc, buffer, 1000);
	if (nb < 1)
	{
		write(2, "Load() failed\n", 14);
	}
	read_save(heros, buffer);
	return (heros);

}

int		write_file(char *file)
{
	int		fd;
	int		ret;
	char	buffer[1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Open() failed\n", 14);
		return (-1);
	}
	ret = read(fd, buffer, 1);
	while (ret != 0)
	{
		write(1, &buffer[0], 1);
		ret = read(fd, buffer, 1);
	}
	if (close(fd) == -1)
	{
		write(2, "Close() failed\n", 15);
		return (-1);
	}
	write(1, "\n", 1);
	return (0);
}