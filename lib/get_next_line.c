#include "include/get_next_line.h"
#include "include/libft.h"

char	*ft_get_line(char *leftovers)
{
	int		i;
	char	*str;

	i = 0;
	if (!leftovers[i])
		return (NULL);
	while (leftovers[i] && leftovers[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (leftovers[i] && leftovers[i] != '\n')
	{
		str[i] = leftovers[i];
		i++;
	}
	if (leftovers[i] == '\n')
	{
		str[i] = leftovers[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_leftovers(char *leftovers)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (leftovers[i] && leftovers[i] != '\n')
		i++;
	if (!leftovers[i])
	{
		free(leftovers);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(leftovers) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (leftovers[i])
		str[j++] = leftovers[i++];
	str[j] = '\0';
	free(leftovers);
	leftovers = NULL;
	return (str);
}

char	*ft_read(int fd, char *text)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(text, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			if (text)
				free(text);
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		text = ft_strjoin(text, buff);
	}
	free(buff);
	return (text);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftovers;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftovers = ft_read(fd, leftovers);
	if (!leftovers)
		return (NULL);
	line = ft_get_line(leftovers);
	leftovers = ft_leftovers(leftovers);
	return (line);
}
