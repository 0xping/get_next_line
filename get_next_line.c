/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:13:27 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/11/12 16:32:02 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*data;
	char		*buff;
	int			rd;
	char		*tmp;
	char		*result;

	result = 0;
	tmp = 0;
	buff = malloc(BUFFER_SIZE + 1);
	if (buff)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
		{
			ft_free(&data, &buff);
			return (0);
		}
		while (rd >= 0)
		{
			buff[rd] = 0;
			data = ft_strjoin(data, buff);
			if (ln_index(data) >= 0)
			{
				tmp = data;
				split_with_nl(&result, &data, data);
				ft_free(&tmp, &buff);
				return (result);
			}
			if (rd == 0)
			{
				(*data) && (result = ft_strdup(data));
				ft_free(&buff, &data);
				return (result);
			}
			rd = read(fd, buff, BUFFER_SIZE);
		}
	}
	return (buff);
}

int	ln_index(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

void	*ft_free(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = 0;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = 0;
	}
	return (0);
}
