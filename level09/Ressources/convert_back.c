#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	convert_back(char *s, size_t len)
{
	char	c;

	for (size_t i = 0; i < len; ++i)
	{
		c = s[i];
		s[i] = c - i;
	}
}

int		main(int ac, char **av)
{
	char		buf[1024] = {0};
	int			fd;
	ssize_t		n;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", av[0]);
		return 1;
	}

	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		perror("open");
		return 1;
	}
	
	n = read(fd, buf, sizeof(buf));
	close(fd);
	if (n < 0 || n > (ssize_t)sizeof(buf))
	{
		perror("read");
		return 1;
	}

	convert_back(buf, n);
	printf("%s\n", buf);

	return 0;
}
