/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:50:30 by atajima           #+#    #+#             */
/*   Updated: 2026/05/07 16:03:47 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_join(const char *str);

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		total_len;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen_join(s1) + ft_strlen_join(s2);
	str = malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

static int	ft_strlen_join(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	*joined;

// 	if (argc != 3)
// 		return (1);
// 	joined = ft_strjoin(argv[1], argv[2]);
// 	printf("%s\n", joined);
// 	free(joined);
// 	return (0);
// }
