/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:09:16 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/02 17:22:06 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;

	new_node = NULL;
	new_node = (t_list*)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = (void*)content;
	new_node->content_size = content_size;
	new_node->next = NULL;
	return (new_node);
}
