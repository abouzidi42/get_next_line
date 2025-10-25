/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:44:43 by anis              #+#    #+#             */
/*   Updated: 2025/10/25 20:08:29 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <fcntl.h> // Pour open()
# include <stdlib.h> // Pour free() et malloc()
# include <unistd.h> // Pour read()

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*verify(char *tmp, char *buff);
void	extract(char	**ptr);
char	*freethis(char **ptr_tmp, char **ptr_buff, ssize_t b);
char	*get_next_line(int fd);

#endif