/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:38:11 by ajones            #+#    #+#             */
/*   Updated: 2021/12/29 16:40:27 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*todel;

	todel = *alst;
	while (todel)
	{
		tmp = todel->next;
		del(todel->content, todel->content_size);
		free(todel);
		todel = tmp;
	}
	*alst = NULL;
}
