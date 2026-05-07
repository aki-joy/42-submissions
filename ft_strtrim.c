/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:32:45 by atajima           #+#    #+#             */
/*   Updated: 2026/05/07 16:17:24 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_trim(const char *s1);
static int	check_set(const char c, const char *set);

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	int		front;
	int		back;
	int		i;

	front = 0;
	back = ft_strlen_trim(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (s1[front] && check_set(s1[front], set))
		front++;
	if (s1[front] == '\0')
		return (ft_strdup(""));
	while (check_set(s1[back], set))
		back--;
	res = malloc(sizeof(char) * (back - front + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (front + i <= back)
	{
		res[i] = s1[front + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
static int	check_set(const char c, const char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_strlen_trim(const char *s1)
{
	int	len;

	len = 0;
	while (s1[len])
		len++;
	return (len);
}

// int	main(int argc, char **argv)
// {
// 	char	*trimmed;

// 	if (argc != 3)
// 		return (1);
// 	trimmed = ft_strtrim(argv[1], argv[2]);
// 	printf("%s\n", trimmed);
// 	free(trimmed);
// 	return (0);
// }
