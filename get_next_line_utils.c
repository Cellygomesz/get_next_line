/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:29:03 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/10/22 21:37:41 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s01;
	char	*s02;
	char	*ptr;
	size_t	i;
	size_t	j;

	s01 = (char *)s1;
	s02 = (char *)s2;
	i = 0;
	j = 0;
	if (s01 == NULL || s02 == NULL)
		return (NULL);
	ptr = (char *)malloc((ft_strlen(s01) + ft_strlen(s02)) + 1);
	while (s01[i])
	{
		ptr[i] = s01[i];
		i++;
	}
	while (s02[j])
	{
		ptr[i + j] = s02[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	size_t			i;
	char			*temp;

	i = 0;
	while (s[i])
		i++;
	temp = (char *)malloc((sizeof(char) * i) + 1);
	i = 0;
	if (temp == NULL)
		return (0);
	else
	{
		while (s[i])
		{
			temp[i] = s[i];
			i++;
		}
	}
	temp[i] = '\0';
	return (temp);
}
