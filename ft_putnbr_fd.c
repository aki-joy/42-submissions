/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:38:54 by akihiro           #+#    #+#             */
/*   Updated: 2026/05/03 19:09:19 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    char    c;

    if (n > 10)
        ft_putnbr_fd(n /10, fd);
    c = n % 10 + '0';
    write(fd, &c, 1);
}
// int main(void)
// {
//     int n = 123;
//     int fd = 1;
//     ft_putnbr_fd(n, fd);
//     return (0);
// }