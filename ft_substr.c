/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:17:58 by atajima           #+#    #+#             */
/*   Updated: 2026/05/08 13:40:35 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alloc_substr(unsigned int start, size_t len, size_t s_len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = 0;
	if (!s)
		return (NULL);
	while (s[s_len])
		s_len++;
	res = alloc_substr(start, len, s_len);
	if (!res)
		return (NULL);
	if (start >= s_len)
		return (res);
	while (s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*alloc_substr(unsigned int start, size_t len, size_t s_len)
{
	char	*res;

	if (s_len <= start)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		*res = '\0';
	}
	else if (s_len - start < len)
	{
		res = malloc(sizeof(char) * (s_len - start + 1));
		if (!res)
			return (NULL);
	}
	else
	{
		res = malloc(sizeof(char) * (len + 1));
		if (!res)
			return (NULL);
	}
	return (res);
}
