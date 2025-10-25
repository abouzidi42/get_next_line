/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:36:16 by anis              #+#    #+#             */
/*   Updated: 2025/10/25 21:42:03 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ret_free(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
	return (NULL);
}

char	*verify(char *tmp, char *buff)
{
	char	*keep_tmp;
	int		len;

	if (tmp)
	{
		keep_tmp = ft_strdup(tmp);
		free (tmp);
		if (!keep_tmp)
			return (NULL);
		len = ft_strlen(keep_tmp) + ft_strlen (buff);
		tmp = (char *)malloc(len + 1);
		if (tmp == NULL)
		{
			free(keep_tmp);
			return (NULL);
		}
		ft_memcpy(tmp, keep_tmp, ft_strlen(keep_tmp) + 1);
		ft_memcpy(ft_strchr(tmp, '\0'), buff, ft_strlen(buff));
		tmp[len] = '\0';
		free(keep_tmp);
		return (tmp);
	}
	return (ft_strdup(buff));
}

void	extract(char	**ptr)
{
	char	*keep_tmp;

	keep_tmp = ft_strdup(ft_strchr(*ptr, '\n') + 1);
	if (!keep_tmp)
	{
		ret_free(ptr);
		return ;
	}
	free(*ptr);
	*ptr = keep_tmp;
}

char	*freethis(char **ptr_tmp, char **ptr_buff, ssize_t b)
{
	char	*line;

	if (*ptr_tmp && **ptr_tmp && b == 0)
	{
		line = ft_strdup(*ptr_tmp);
		ret_free(ptr_tmp);
		if (!line)
			return (ret_free(ptr_buff));
		ret_free(ptr_buff);
		return (line);
	}
	if (*ptr_tmp && ft_strchr(*ptr_tmp, '\n'))
	{
		line = ft_substr(*ptr_tmp, 0,
				ft_strchr(*ptr_tmp, '\n') - *ptr_tmp + 1);
		if (!line)
			return (ret_free(ptr_tmp));
		extract(ptr_tmp);
		return (line);
	}
	ret_free(ptr_tmp);
	return (ret_free(ptr_buff));
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*tmp;
	ssize_t		read_bytes;

	buff = NULL;
	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ret_free(&tmp));
	while (read_bytes != 0)
	{
		if (tmp && ft_strchr(tmp, '\n') != NULL)
			return (freethis(&tmp, &buff, read_bytes));
		buff = (char *)malloc(BUFFER_SIZE + 1);
		if (buff == NULL)
			return (ret_free(&tmp));
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buff[read_bytes] = '\0';
		tmp = verify(tmp, buff);
		free(buff);
		if (!tmp)
			return (ret_free(&tmp));
	}
	return (freethis(&tmp, &buff, read_bytes));
}
