/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:32:45 by atajima           #+#    #+#             */
/*   Updated: 2026/04/27 18:00:49 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_set(const char *a1, const char *set, int len);

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		len;
	int		flag;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	flag = check_set(s1, set, len);
	if (flag == 'I' || flag == 'L')
		len -= 1;
	if (flag == 'B')
		len -= 2;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (*s1)
	{
		
	}
}

int	check_set(const char *s1, const char *set, int len)
{
	int		i;
	char	flag;

	i = 0;
	flag = 'N';
	while (set[i])
	{
		if (s1[0] == set[i])
			flag = 'I';
		if (s1[len - 1] == set[i] && flag == 0)
			flag = 'L';
		if (s1[len - 1] == set[i] && flag == 1)
			flag = 'B';
		i++;
	}
	return (flag);
}

int	ft_strlen(char *s1)
{
	int	len;

	len = 0;
	while (s1[len])
		len++;
	return (len);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*trimmed;

	if (argc != 3)
		return (1);
	trimmed = ft_strtrim(argv[1], argv[2]);
	printf("%s\n", trimmed);
	free(trimmed);
	return (0);
}
