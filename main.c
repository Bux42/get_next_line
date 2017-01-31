#include <fcntl.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	(void)ac;
	int fd;
	int ret;
	char *str;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &str)))
	{
		ft_putendl(str);
	}
	close(fd);
	return (0);
}
