/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:04:36 by atajima           #+#    #+#             */
/*   Updated: 2026/04/28 13:17:18 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	word_count(char const *s, char c);
int	ft_strlen(char const *s, char c);
char const	*insert(char const *s, char c, char **ans);

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;
	int		j;

	i = word_count(s, c);
	ans = malloc(sizeof(char *) * (i + 1));
	if (!ans)
		return (NULL);
	ans[i] = NULL;
	j = 0;
	while (i > j)
	{
		insert(s, c, &ans[j]);
		if(!ans[j])
			return (NULL);
		j++;
	}
	return (ans);
}

int	word_count(char const *s, char c)
{
	int	i;
	int flag;
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

int	ft_strlen(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*s == c)
		s++;
	while (s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char const	*insert(char const *s, char c, char **ans)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(s, c);
	ans[i] = malloc(sizeof(char) * (len + 1));
	if (!ans[i])
		return (NULL);
	ans[i][len] = '\0';
	while (j < len)
	{
		ans[i][j] = *s;
		j++;
		s++;
	}
	ans[i][j] = '\0';
	return (s);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**splited;
	int		i;
	int		count;

	i = 0;
	if (argc != 4)
		return (1);
	count = atoi(argv[3]);
	splited = ft_split(argv[1], argv[2][0]);
	while (i <= count)
	{
		printf ("%s\n", splited[i]);
		i++;
	}
	i = 0;
	while (i <= count)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	return (0);
}