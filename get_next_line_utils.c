/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:29:03 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/10/24 17:04:42 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s2 && s2[len])
		len++;
	while (s2 && s2[i])
		i++;
	s = ft_bzero(len + i + 1, sizeof * s);
	if (!s)
		return (NULL);
	len = -1;
	while (s1 && s1[++len])
		s[len] = s1[len];
	i = -1;
	while (s2 && s2[++i])
		s[len + i] = s2[i];
	return (s);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s1)
		return (ft_strdup(""));
	while (s1[i])
		i++;
	s2 = ft_bzero(i + 1, sizeof * s2);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

void	*ft_bzero(size_t count, size_t size)
{
	void			*r;
	unsigned char	*p;
	size_t			allsize;

	allsize = count * size;
	r = malloc(allsize);
	if (!r)
		return (NULL);
	p = (unsigned char *)r;
	while (allsize != 0)
	{
		*p = '\0';
		p++;
		allsize--;
	}
	return (r);
}

void	my_free(char **str, char **str2, char **str3)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}
