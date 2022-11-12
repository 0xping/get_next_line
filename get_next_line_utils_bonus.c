/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:13:34 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/11/12 18:36:17 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	p = malloc(ft_strlen(s1) + 1);
	i = 0;
	if (p)
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = 0;
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result)
	{
		i = 0;
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
			result[i++] = s2[j++];
		result[i] = 0;
	}
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (slen - start < len)
		len = slen - start;
	subs = malloc(len + 1);
	if (subs)
	{
		i = 0;
		while (i < len && s[start + i])
		{
			subs[i] = s[start + i];
			i++;
		}
		subs[len] = 0;
	}
	return (subs);
}

void	split_with_nl(char **s1, char **s2, char *s3)
{
	*s1 = ft_substr(s3, 0, ln_index(s3) + 1);
	*s2 = ft_strdup(s3 + ln_index(s3) + 1);
}
