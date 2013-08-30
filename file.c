#include "heros.h"

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