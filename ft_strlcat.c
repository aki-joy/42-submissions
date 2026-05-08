/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:10:34 by atajima           #+#    #+#             */
/*   Updated: 2026/05/08 13:37:03 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = 0;
	len2 = 0;
	while (len1 < size && dest[len1])
		len1++;
	while (src[len2])
		len2++;
	if (size <= len1)
		return (size + len2);
	i = 0;
	while (src[i] && size - 1 > len1 + i)
	{
		dest[len1 + i] = src[i];
		i++;
	}
	dest[len1 + i] = '\0';
	return (len1 + len2);
}
