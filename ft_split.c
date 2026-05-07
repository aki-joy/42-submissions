/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:04:36 by atajima           #+#    #+#             */
/*   Updated: 2026/05/07 17:15:50 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			word_count(char const *s, char c);
static int			ft_strlen_split(char const *s, char c);
static char const	*insert(char const *s, char c, char *ans);
static void			free_all(char **ans, int j);

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = word_count(s, c);
	ans = malloc(sizeof(char *) * (i + 1));
	if (!ans)
		return (NULL);
	ans[i] = NULL;
	j = 0;
	while (j < i)
	{
		s = insert(s, c, ans[j]);
		if (!ans[j])
		{
			free_all(ans, j);
			return (NULL);
		}
		j++;
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

static char const	*insert(char const *s, char c, char *ans)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_split(s, c);
	ans = malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	ans[len] = '\0';
	while (*s == c)
		s++;
	while (i < len)
	{
		ans[i] = *s;
		i++;
		s++;
	}
	ans[i] = '\0';
	return (s);
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
//int	main(int argc, char **argv)
//{
//	char	**splited;
//	int		i;
//	int		count;

//	i = 0;
//	if (argc != 4)
//		return (1);
//	count = atoi(argv[3]);
//	splited = ft_split(argv[1], argv[2][0]);
//	while (i < count)
//	{
//		printf("%s\n", splited[i]);
//		i++;
//	}
//	i = 0;
//	while (i <= count)
//	{
//		free(splited[i]);
//		i++;
//	}
//	free(splited);
//	return (0);
//}
