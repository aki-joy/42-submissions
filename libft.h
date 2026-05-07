/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:22:28 by akihiro           #+#    #+#             */
/*   Updated: 2026/05/07 16:06:28 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif
