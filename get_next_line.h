/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:29:43 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/10/22 13:50:21 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFER_SIZE 10
# endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
} t_list;

char	*get_next_line(int fd);

#endif
