/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:24:28 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/10/28 10:13:35 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*keep = NULL;
	char		*tmp;
	char		*line;

	tmp = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lineread(fd, &keep, &tmp);
	if (keep != NULL && *keep != '\0')
		line = lineparse(&keep, &tmp);
	if (!line || *line == '\0')
	{
		my_free(&keep, &line, &tmp);
		return (NULL);
	}
	return (line);
}

char	*lineparse(char **keep, char **tmp)
{
	char	*line;

	*tmp = ft_strdup(*keep);
	if (!*tmp)
		return (NULL);
	my_free(keep, NULL, NULL);
	*keep = after_newline(*tmp);
	line = before_newline(*tmp);
	my_free(tmp, NULL, NULL);
	return (line);
}

void	lineread(int fd, char **keep, char **tmp)
{
	char	*buf;
	int		r;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			my_free(&buf, keep, tmp);
			return ;
		}
		buf[r] = '\0';
		*tmp = ft_strdup(*keep);
		my_free(keep, 0, 0);
		*keep = ft_strjoin(*tmp, buf);
		my_free(tmp, 0, 0);
		if (found_newline(*keep))
			break ;
	}
	my_free(&buf, 0, 0);
}

char	*after_newline(const char *s)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	len = 0;
	while (s[i + len])
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		res[j] = s[i + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*before_newline(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = (char *)malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}
