/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:14:10 by atajima           #+#    #+#             */
/*   Updated: 2026/05/08 18:01:32 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digit(long num);
static void		convert(char *res, long num, int *i);

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		sign;
	int		i;

	num = n;
	i = 0;
	sign = 0;
	if (num < 0)
	{
		sign = -1;
		num = num * -1;
	}
	res = malloc(sizeof(char) * (count_digit(num) + (sign < 0) + 1));
	if (!res)
		return (NULL);
	if (sign < 0)
	{
		res[i] = '-';
		i++;
	}
	convert(res, num, &i);
	res[i] = '\0';
	return (res);
}

static int	count_digit(long num)
{
	int	count;

	count = 1;
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static void	convert(char *res, long num, int *i)
{
	if (num >= 10)
		convert(res, num / 10, i);
	res[*i] = num % 10 + '0';
	(*i)++;
}
