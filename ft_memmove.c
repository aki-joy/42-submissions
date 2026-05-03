/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:42:36 by atajima           #+#    #+#             */
/*   Updated: 2026/05/03 19:08:53 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*s;

	p = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (p < s)
	{
		while (n > 0)
		{
			*p = *s;
			p++;
			s++;
			n--;
		}
		return (dest);
	}
	while (n > 0)
	{
		p[n - 1] = s[n - 1];
		n--;
	}
	return (dest);
}
