/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:17:58 by atajima           #+#    #+#             */
/*   Updated: 2026/04/27 15:48:15 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_malloc(unsigned int start, size_t len, int s_len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = 0;
	if (!s)
		return (NULL);
	while (s[s_len])
		s_len++;
	str = ft_malloc(start, len, s_len);
	if (!str)
		return (NULL);
	if (start >= s_len)
		return (str);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

char	*ft_malloc(unsigned int start, size_t len, int s_len)
{
	char	*str;

	if (s_len <= start)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (s_len < start + len)
	{
		str = malloc(sizeof(char) * (s_len - start + 1));
		if (!str)
			return (NULL);
		str[s_len - start] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
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
