/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:27:33 by atajima           #+#    #+#             */
/*   Updated: 2026/05/02 19:48:05 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if ((*lst) == NULL)
    {
        *lst = new;
        return ;
    }
    while ((*lst)->next != NULL)
        (*lst)->next = (*lst)->next;
    (*lst)->next = new;
    new->next = NULL;
}