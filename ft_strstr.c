/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:00:38 by atajima           #+#    #+#             */
/*   Updated: 2026/04/25 20:49:24 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(const char *heystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	while (heystack[i])
	{
		j = 0;
		while (heystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&heystack[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	char heystack[] = "hello world";
// 	char needle[] = "ll";
// 	printf("%s", ft_strstr(heystack, needle));
// 	return (0);
// }