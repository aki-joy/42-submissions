/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:25:48 by atajima           #+#    #+#             */
/*   Updated: 2026/04/25 18:35:53 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (0);
	while (*src && size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = '\0';
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
