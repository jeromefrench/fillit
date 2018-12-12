/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:38:57 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/12 17:04:07 by jchardin         ###   ########.fr       */
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
        //printf("\nUne coordonee =%d et le next= %p", local_lst->point[2].x, local_lst->next);
        local_lst = local_lst->next;
    }
    return ; 
}

int         ft_check_for_contact(t_piece *lst)
{
    int     k;
    int     i;
    int     piece_ok;

    t_piece *local_lst;
    local_lst = lst;
    while (local_lst != NULL)
    {
        k = 0;
        while (k < 4)
        {
            piece_ok = 0;
            //printf("\n\n");
            i = 0;
            while(i < 4)
            {
                if(i !=  k)
                {
                    //printf("Le k=%d et le i=%d\n", k, i);
                    if (!(local_lst->point[k].x == local_lst->point[i].x + 1 ||  
                                local_lst->point[k].x == local_lst->point[i].x - 1 ||  
                                local_lst->point[k].x == local_lst->point[i].y + 1 ||  
                                local_lst->point[k].x == local_lst->point[i].y - 1))
                    {
                        //printf("Le k vaut =%d   -->  NON\n", k);
                    }
                    else
                    {
                        //printf("Le k vaut =%d   -->  OUI\n", k);
                        piece_ok = 1;
                    }
                        
                }
                i++;
            }
            k++;
            if(!piece_ok)
                return (0);
        }
        local_lst = local_lst->next;
    }
    ft_putstr(" OK\n");
    return (1);
}
