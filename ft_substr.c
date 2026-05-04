/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:17:58 by atajima           #+#    #+#             */
/*   Updated: 2026/05/04 18:41:39 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	res = copy(s, start, len, s_len);
	if (*res == '\0')
		return (res);
	while (s[s_len + i] && i < len)
	{
		
	}
}

char	*copy(char const *s, unsigned int start, size_t len, size_t s_len)
{
	char	*res;

	if (s_len - 1 <= start)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		*res = '\0';
	}
	else if (s_len - 1 < start + len)
	{
		res = malloc(sizeof(char) * (start + len - s_len + 2));
		if (!res)
			return (NULL);
	}
	else
	{
	res = malloc(sizeof(char) * (start + len + 1));
	if (!res)
		return (NULL);
	}
	return (res);
}


// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	int		start;
// 	int		len;
// 	char	*sub;

// 	if (argc != 4)
// 		return (0);
// 	start = atoi(argv[2]);
// 	len = atoi(argv[3]);
// 	sub = ft_substr(argv[1], start, len);
// 	if (!sub)
// 		return (1);
// 	printf ("%s\n", sub);
// 	free(sub);
// 	return (0);
// }
