/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:25:48 by atajima           #+#    #+#             */
/*   Updated: 2026/05/07 15:55:43 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (src[j] && size - 1 > j)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char dest[10];
// 	char src[] = "hello world";
// 	size_t size = 4;
// 	printf("%d\n", (int)ft_strlcpy(dest, src, size));
// 	printf("%s", dest);
// 	return (0);
// }
