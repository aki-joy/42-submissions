/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:17:58 by atajima           #+#    #+#             */
/*   Updated: 2026/05/04 19:49:18 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*copy(unsigned int start, size_t len, size_t s_len);

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
		printf ("%zu\n", s_len);
	res = copy(start, len, s_len);
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

char	*copy(unsigned int start, size_t len, size_t s_len)
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

int	main(int argc, char **argv)
{
	size_t		start;
	size_t		len;
	char	*sub;

	if (argc != 4)
		return (0);
	start = atoi(argv[2]);
	len = atoi(argv[3]);
	sub = ft_substr(argv[1], start, len);
	if (!sub)
		return (1);
	printf ("%s\n", sub);
	free(sub);
	return (0);
}
