/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:32:45 by atajima           #+#    #+#             */
/*   Updated: 2026/05/11 16:01:21 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_trim(const char *s1);
static int	check_set(const char c, const char *set);
static char	*make_trimmed(const char *s1, int front, int back);

char	*ft_strtrim(const char *s1, const char *set)
{
	int		front;
	int		back;

	front = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[front] && check_set(s1[front], set))
		front++;
	if (s1[front] == '\0')
		return (ft_strdup(""));
	back = ft_strlen_trim(s1) - 1;
	while (check_set(s1[back], set))
		back--;
	return (make_trimmed(s1, front, back));
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

static char	*make_trimmed(const char *s1, int front, int back)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (back - front + 2));
	if (!res)
		return (NULL);
	while (i + front <= back)
	{
		res[i] = s1[i + front];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	ft_strlen_trim(const char *s1)
{
	int	len;

	len = 0;
	while (s1[len])
		len++;
	return (len);
}
