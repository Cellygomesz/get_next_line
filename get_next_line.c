/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:24:28 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/10/22 11:05:17 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	int	i = 0;
	
	buffer = (char *)malloc(sizeof(char *));
	if (!buffer)
		return ;

	while (buffer[0] != '\n')
	{
		read(fd, buffer, 1);
		printf("%s", buffer);
		i++;
	}
	return (buffer);
}

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
