/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:24:28 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/10/23 11:53:37 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 1- receber um arquivo (descritor de arquivo)
// 2- ler a primeira linha desse arquivo
// 3- guardo em algum lugar até o \n
// 4- dou free() no resto 
// 5- chamo dnv a função
// 6- guardo mais uma linha até o \n
// 7- dou free() no resto

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*pos; //o que restou da ultima chamada
	int			rtn;

	if (pos == NULL)
		pos = ft_strdup("");
	buf = (char *)malloc((BUFFER_SIZE +1) * sizeof(char));
	if (!buf)
		return (NULL);
	rtn = read(fd, buf, BUFFER_SIZE);
	if (rtn < 0 || BUFFER_SIZE == 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char	*str;
	int fd = open("test.txt", O_RDONLY);

	str = get_next_line(fd);
	printf("%s\n", str);
	return (0);
}
