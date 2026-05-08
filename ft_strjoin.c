/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:50:30 by atajima           #+#    #+#             */
/*   Updated: 2026/05/08 13:36:37 by akihiro          ###   ########.fr       */
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
