/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:44:32 by atajima           #+#    #+#             */
/*   Updated: 2026/04/25 19:00:30 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*s)
	{
		if (*s == c)
			p = (char *)s;
		s++;
	}
	return (p);
}
// #include <stdio.h>
//  int main(void)
//  {
// 	char s[] = "hello world";
// 	printf("%s", ft_strrchr(s, 108));
// 	return (0);
// }
