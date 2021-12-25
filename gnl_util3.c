#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr3(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin3(char *dest, char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!dest)
	{
		dest = (char *)malloc(1 * sizeof(char));
		dest[0] = '\0';
	}
	if (!dest || !src)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(dest) + ft_strlen(src)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (dest)
		while (dest[++i] != '\0')
			str[i] = dest[i];
	while (src[j] != '\0')
		str[i++] = src[j++];
	str[ft_strlen(dest) + ft_strlen(src)] = '\0';
	free(dest);
	return (str);
}

char	*ft_get_line(char *dest)
{
	int		i;
	char	*str;

	i = 0;
	if (!dest[i])
		return (NULL);
	while (dest[i] && dest[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (dest[i] && dest[i] != '\n')
	{
		str[i] = dest[i];
		i++;
	}
	if (dest[i] == '\n')
	{
		str[i] = dest[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *dest)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (dest[i] && dest[i] != '\n')
		i++;
	if (!dest[i])
	{
		free(dest);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(dest) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (dest[i])
		str[j++] = dest[i++];
	str[j] = '\0';
	free(dest);
	return (str);
}
