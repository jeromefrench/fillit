/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:38:57 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/12 14:46:50 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_tetriminos.h"

t_piece     *ft_lst_new_piece(t_piece *new_node)
{
    new_node = (t_piece*)malloc(sizeof(t_piece));
    new_node->point = (t_point*)malloc(sizeof(t_point) * 4);
    new_node->next = NULL;
    return (new_node);
}

void        ft_lst_add(t_piece **lst, t_piece *new_node)
{
    if(*lst != NULL && new_node !=NULL)
    {
        new_node->next = *lst;
        *lst = new_node;
    }
    if (*lst == NULL)
    {
        *lst = new_node;
    }
    return ;
}

void        ft_display_lst_piece(t_piece *lst)
{
    t_piece *local_lst;
    local_lst = lst;

    
    while (local_lst != NULL)
    {
        printf("\nUne coordonee =%d et le next= %p", local_lst->point[2].x, local_lst->next);
        local_lst = local_lst->next;
    }
    return ; 
}
