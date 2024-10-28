/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:14:55 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/10/28 10:16:10 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*frase;

	fd = open("test.txt", O_RDONLY);
	frase = get_next_line(fd);
	while (frase)
	{
		printf("%s", frase);
		free(frase);
		frase = get_next_line(fd);
	}
	close(fd);
	return (0);
}
