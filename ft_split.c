/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:04:36 by atajima           #+#    #+#             */
/*   Updated: 2026/05/08 18:47:54 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			word_count(char const *s, char c);
static int			ft_strlen_split(char const *s, char c);
static char			*insert(char const *s, char c, char *ans);
static void			free_all(char **ans, int j);

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	ans = malloc(sizeof(char *) * (count + 1));
	if (!ans)
		return (NULL);
	ans[count] = NULL;
	i = -1;
	while (++i < count)
	{
		while (*s == c)
			s++;
		ans[i] = insert(s, c, ans[i]);
		if (!ans[i])
			return (free_all(ans, i), NULL);
		while (*s && *s != c)
			s++;
	}
	return (ans);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		if (s[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	return (count);
}

static int	ft_strlen_split(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static char	*insert(char const *s, char c, char *ans)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_split(s, c);
	ans = malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	ans[len] = '\0';
	while (i < len)
	{
		ans[i] = s[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

static void	free_all(char **ans, int j)
{
	while (j >= 0)
	{
		free(ans[j]);
		j--;
	}
	free(ans);
}
