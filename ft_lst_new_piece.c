/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:38:57 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/16 17:49:47 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_tetriminos.h"

t_piece			*ft_lst_new_piece(t_piece *new_node)
{
	new_node = (t_piece*)malloc(sizeof(t_piece));
	new_node->point = (t_point*)malloc(sizeof(t_point) * 4);
	new_node->move.x = 0;
	new_node->move.y = 0;
	new_node->next = NULL;
	return (new_node);
}

void			ft_lst_add(t_piece **lst, t_piece *new_node)
{
	if (*lst != NULL && new_node != NULL)
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

void			ft_check_for_contact_decoupe(t_piece *lst,
int *connexions, int *i, int *k)
{
	if (lst->point[*k].x == lst->point[*i].x)
	{
		if (lst->point[*k].y == lst->point[*i].y - 1)
			(*connexions)++;
		if (lst->point[*k].y == lst->point[*i].y + 1)
			(*connexions)++;
	}
	if (lst->point[*k].y == lst->point[*i].y)
	{
		if (lst->point[*k].x == lst->point[*i].x - 1)
			(*connexions)++;
		if (lst->point[*k].x == lst->point[*i].x + 1)
			(*connexions)++;
	}
}

int				ft_check_for_contact(t_piece *lst)
{
	int		k;
	int		i;
	int		connexions;

	while (lst != NULL)
	{
		k = 0;
		connexions = 0;
		while (k < 4)
		{
			i = 0;
			while (i < 4)
			{
				if (i != k)
					ft_check_for_contact_decoupe(lst, &connexions, &k, &i);
				i++;
			}
			k++;
		}
		if (connexions <= 4)
			return (0);
		lst = lst->next;
	}
	return (1);
}
