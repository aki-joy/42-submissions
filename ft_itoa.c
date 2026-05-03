/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:14:10 by atajima           #+#    #+#             */
/*   Updated: 2026/05/03 19:08:01 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_digit(long num, int sign);
void	convert(char *str, long num, int *i, int sign);

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		i;
	int		sign;

	num = n;
	i = 0;
	sign = 0;
	if (num < 0)
	{
		num *= -1;
		sign = 1;
	}
	if (num == 0)
		sign = 2;
	str = malloc(sizeof(char) * (count_digit(num, sign) + 1));
	if (!str)
		return (NULL);
	convert(str, num, &i, sign);
	str[i] = '\0';
	return (str);
}

int	count_digit(long num, int sign)
{
	int	count;

	count = 0;
	if (sign == 2)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	if (sign == 1)
		count++;
	return (count);
}

void	convert(char *str, long num, int *i, int sign)
{
	if (sign == 2)
	{
		str[*i] = '0';
		(*i)++;
		return ;
	}
	if (sign == 1)
	{
		str[*i] = '-';
		sign = 0;
		(*i)++;
	}
	if (num >= 10 && sign == 0)
		convert(str, num / 10, i, sign);
	str[*i] = num % 10 + '0';
	(*i)++;
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	while (i < argc)
	{
		str = ft_itoa(atoi(argv[i]));
		printf("%s\n", str);
		free(str);
		i++;
	}
	return (0);
}
