/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:10:34 by atajima           #+#    #+#             */
/*   Updated: 2026/04/25 16:25:19 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = 0;
	len2 = 0;
	while (dest[len1])
		len1++;
	while (src[len2])
		len2++;
	if (size <= len1)
		return (size + len2);
	i = 0;
	while (size - 1 > len1 + i)
	{
		dest[len1 + i] = src[i];
		i++;
	}
	dest[len1 + i] = '\0';
	return (len1 + len2);
}
//#include <stdio.h>
// int	main(void)
// {
// 	char	dest[10] = "abc";
// 	char	src[] = "def";
// 	size_t	size = 6;

// 	printf("%d\n", (int)ft_strlcat(dest, src, size));
// 	printf("%s", dest);
// 	return (0);
// }
