/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:06:38 by jislim            #+#    #+#             */
/*   Updated: 2021/12/12 17:05:58 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	count_word(char *s, char c)
{
	size_t	word_cnt;
	size_t	i;

	word_cnt = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word_cnt++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (word_cnt);
}

char	**count_len(char **str, char *s, char c)
{
	size_t	s_i;
	size_t	str_i;
	size_t	word_len;

	s_i = 0;
	str_i = 0;
	while (s[s_i] != '\0')
	{
		word_len = 0;
		if (s[s_i] != c)
		{
			while (s[s_i] != c && s[s_i] != '\0')
			{
				word_len++;
				s_i++;
			}
			str[str_i] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (!str[str_i])
				return (NULL);
			str_i++;
		}
		else
			s_i++;
	}
	return (str);
}

char	**fill_str_split(char **str, char *s, char c, int word_cnt)
{
	size_t	s_i;
	size_t	str_i;
	size_t	i;

	s_i = 0;
	str_i = 0;
	while (s[s_i] == c)
		s_i++;
	while (s[s_i] != '\0')
	{
		i = 0;
		while (s[s_i] && s[s_i] != c)
			str[str_i][i++] = s[s_i++];
		str[str_i][i] = '\0';
		while (s[s_i] == c && c != 0)
			s_i++;
		str_i++;
	}
	str[word_cnt] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	word_cnt;

	if (s == NULL)
		return (NULL);
	if (!ft_strlen(s))
	{
		str = malloc(sizeof(char *) * 1);
		*str = 0;
		return (str);
	}
	word_cnt = count_word((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (str == NULL)
		return (NULL);
	str = count_len(str, (char *)s, c);
	if (str == NULL)
	{
		free_all(str);
		return (NULL);
	}
	str = fill_str_split(str, (char *)s, c, word_cnt);
	return (str);
}
