/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:44:32 by atajima           #+#    #+#             */
/*   Updated: 2026/05/04 23:41:14 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (*s)
	{
		if (*s == c)
			p = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (p);
}
// #include <stdio.h>
//  int main(void)
//  {
// 	char s[] = "hello world";
// 	printf("%s", ft_strrchr(s, 108));
// 	return (0);
// }
