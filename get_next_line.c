/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:13:27 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/11/12 18:32:21 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct s_data
{
	char	**stc;
	char	**result;
	char	**buff;
}			t_data;

char	*get_line(t_data *data, int fd, ssize_t rd)
{
	char	*tmp;

	while (rd >= 0)
	{
		(*(data->buff))[rd] = 0;
		tmp = *(data->stc);
		*(data->stc) = ft_strjoin(*(data->stc), *(data->buff));
		ft_free(&tmp, 0);
		if (ln_index(*(data->stc)) >= 0)
		{
			tmp = *(data->stc);
			split_with_nl(data->result, data->stc, *(data->stc));
			ft_free(&tmp, data->buff);
			return (*(data->result));
		}
		if (rd == 0)
		{
			(**data->stc) && (*(data->result) = ft_strdup(*(data->stc)));
			ft_free(data->buff, data->stc);
			return (*(data->result));
		}
		rd = read(fd, *(data->buff), BUFFER_SIZE);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stc;
	char		*buff;
	int			rd;
	char		*result;
	t_data		data;

	result = 0;
	buff = malloc(BUFFER_SIZE + 1);
	if (buff)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
		{
			ft_free(&stc, &buff);
			return (0);
		}
		data.stc = &stc;
		data.buff = &buff;
		data.result = &result;
		return (get_line(&data, fd, rd));
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
