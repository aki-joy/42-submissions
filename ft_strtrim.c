/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:32:45 by atajima           #+#    #+#             */
/*   Updated: 2026/05/04 18:03:25 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s1);
int	check_set(const char c, const char *set);

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	int		front;
	int		back;
	int		i;

	front = 0;
	back = ft_strlen(s1) - 1;
	while (check_set(s1[front], set))
		front++;
		// write (1, &s1[front], 1);
		// write (1, "\n", 1);
	while (check_set(s1[back], set))
		back--;
		// write (1, &s1[back], 1);
		// write (1, "\n", 1);
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
int	check_set(const char c, const char *set)
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

int	ft_strlen(const char *s1)
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
