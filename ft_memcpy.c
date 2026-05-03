/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 19:37:55 by atajima           #+#    #+#             */
/*   Updated: 2026/05/03 19:08:38 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*s;

	p = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n > 0)
	{
		*p = *s;
		p++;
		s++;
		n--;
	}
	return (dest);
}
