/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:29:43 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/10/22 21:41:41 by mgomes-s         ###   ########.fr       */
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

char	*get_next_line(int fd);
size_t  ft_strlen(const char *str);
char    ft_strchr(char *str, int c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s);

#endif
