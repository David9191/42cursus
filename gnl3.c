#include "get_next_line.h"
#include <unistd.h>

char	*ft_read_to_backup(int fd, char *backup)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr3(backup, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		backup = ft_strjoin3(backup, buff);
	}
	free(buff);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = ft_read_to_backup(fd, backup);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_new_left_str(backup);
	return (line);
}

int	main(void)
{
	char	*buf = "start\n";
	int		fd;

	fd = open("hello.txt", O_RDWR);
	while (1)
	{
		buf = get_next_line(fd);
		if (!ft_strlen(buf))
			break ;
		printf("%s", buf);
		free(buf);
	}
}
