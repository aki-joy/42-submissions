/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:14:10 by atajima           #+#    #+#             */
/*   Updated: 2026/05/04 15:26:13 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_digit(long num, int sign);
void	convert(char *res, long num, int *i);

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		sign;
	int		i;

	num = n;
	i = 0;
	if (num == 0)
		sign = 0;
	if (num < 0)
	{
		sign = -1;
		num = num * -1;
	}
	res = malloc(sizeof(char) * (count_digit(num, sign) + 1));
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

int	count_digit(long num, int sign)
{
	int	count;

	count = 0;
	if (sign == 0 || sign == -1)
		count++;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

void	convert(char *res, long num, int *i)
{
	if (num >= 10)
		convert(res, num / 10, i);
	res[*i] = num % 10 + '0';
	(*i)++;
}

int	main(void)
{
	int nbr = 2147483647;
	printf("%s\n", ft_itoa(nbr));
	return (0);
}
