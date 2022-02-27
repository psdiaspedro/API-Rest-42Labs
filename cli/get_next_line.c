#include "cli.h"

static void	writewithprotec(char **old, char **new, char *buf, int i)
{
	char	holder;

	if (!*new)
	{
		holder = buf[i + 1];
		buf[i + 1] = '\0';
		*new = ft_strjoin(buf, "");
		buf[i + 1] = holder;
	}
	else
	{
		*old = *new;
		holder = buf[i + 1];
		buf[i + 1] = '\0';
		*new = ft_strjoin(*old, buf);
		buf[i + 1] = holder;
		free(*old);
	}
}

static void	writefullbuf(char **old, char **new, char *buf)
{
	if (!*new)
		*new = ft_strjoin(buf, "");
	else
	{
		*old = *new;
		*new = ft_strjoin(*old, buf);
		free(*old);
	}
	buf[0] = '\0';
}

static void	writepartialbuf(char **old, char **new, char *buf, int *size)
{
	int	i;

	if (ft_strnchr(buf, BUFFER_SIZE, '\n'))
		*size = 0;
	i = 0;
	while (buf[i] != '\n' && buf[i])
		++i;
	writewithprotec(old, new, buf, i);
	++i;
	ft_memmove(buf, &buf[i], BUFFER_SIZE - i);
	buf[BUFFER_SIZE - i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*new;
	char		*old;
	int			size;

	size = 1;
	new = NULL;
	if (*buf)
		writepartialbuf(&old, &new, buf, &size);
	while (size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		buf[size] = '\0';
		if (size == BUFFER_SIZE && !ft_strnchr(buf, BUFFER_SIZE, '\n'))
			writefullbuf(&old, &new, buf);
		else if (size)
			writepartialbuf(&old, &new, buf, &size);
	}
	return (new);
}
