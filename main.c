/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:19:22 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/16 19:37:46 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_tetriminos.h"

int				ft_x_inside_the_map(t_piece *list_piece, int n, int size_map)
{
	printf("ft_x_inside_the_map, n=%d\n", n);
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (list_piece)
	{
		j = 0;
		if (k == n)
		{
			while (j < 4)
			{
				printf("les coordonne x =%d\n", list_piece->point[j].x + list_piece->move.x);
				if (list_piece->point[j].x + list_piece->move.x > size_map)
					return (0);
				j++;
			}
		}
		k++;
		list_piece = list_piece->next;
	}
	return (1);
}

int				ft_y_inside_the_map(t_piece *list_piece, int n, int size_map)
{
	printf("ft_y_inside_the_map, n=%d\n", n);
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (list_piece)
	{
		printf("piece n=%d\n", i);
		j = 0;
		if (k == n)
		{
			while (j < 4)
			{
				printf("AAAAAAAAAAAAAAAAaa les coordonne y =%d\n", list_piece->point[j].y + list_piece->move.y);
				if (list_piece->point[j].y + list_piece->move.y > size_map)
					return (0);
				j++;
			}
		}
		i++;
		k++;
		list_piece = list_piece->next;
	}
	return (1);
}

int				ft_test_colision(t_piece *list_piece, int n)
{
	printf("ft_test_colision, n=%d\n", n);
	t_piece		*local_list;
	int			k;
	int			i;

	local_list = list_piece;
	k = 0;
	while (k != n)
	{
		k++;
		local_list = local_list->next;
	}
	k = 0;
	while (k < n)
	{
		i = 0;
		while (i < 4)
		{
			if (local_list->point[i].y + local_list->move.y == list_piece->point[i].y + list_piece->move.y)
			{
				if (local_list->point[i].x + local_list->move.x == list_piece->point[i].x + list_piece->move.x)
					return (0);
			}
			i++;
		}
		k++;
		list_piece = list_piece->next;
	}
	return (1);
}

t_piece			*ft_x_plus_one(t_piece **list_piece, int n)
{
	printf("ft_x_plus_one\n");
	printf("Le n =%d\n", n);
	ft_display_pieces(*list_piece);
	
	int			k;
	t_piece		*local_list;

	local_list = *list_piece;
	k = 0;
	while (k != n)
	{
	printf("a\n");
		
		*list_piece = (*list_piece)->next;
		k++;
	}
	(*list_piece)->move.x = (*list_piece)->move.x + 1;
	return (local_list);
}

t_piece			*ft_y_plus_one_x_to_zero(t_piece **list_piece, int n)
{
	printf("ft_y_plus one\n");
	int			k;
	t_piece		*local_list;

	local_list = *list_piece;
	k = 0;
	while (k != n)
	{
		*list_piece = (*list_piece)->next;
		k++;
	}
	(*list_piece)->move.y = (*list_piece)->move.y + 1;
	(*list_piece)->move.x = 0;
	return (local_list);
}

int				ft_put_the_piece(t_piece **list_piece, int n, int next_zone, int size_map)
{
	printf("ft_put_the_piece, n=%d\n", n);
	
	if (next_zone == 1)
	{
		*list_piece = ft_x_plus_one(list_piece, n);
		next_zone = 0;
	}

	if (ft_y_inside_the_map(*list_piece, n, size_map) == 0)
	{
		printf("y n'est pas dans la map\n");
		return (0);
	}
	if (ft_x_inside_the_map(*list_piece, n, size_map) == 1)
	{
		if (ft_test_colision(*list_piece, n) == 1)
		{
			return (1);
		}
		else
		{
			*list_piece = ft_x_plus_one(list_piece, n);
			ft_put_the_piece(list_piece, n, 0, size_map);
		}
	}
	else
	{
		*list_piece = ft_y_plus_one_x_to_zero(list_piece, n);
		ft_put_the_piece(list_piece, n, 0, size_map);
	}
	return (1);
}

int				ft_piece_n_plus_one_exist(t_piece *list_piece, int n)
{
	printf("ft_piece_n_plus_one_exist, n=%d\n", n);
	int		k;

	k = 0;

	while (k != n)
	{
		list_piece = list_piece->next;
		k++;
	}
	printf("HELLO\n");
	printf("une data =%d\n", list_piece->point[1].x);
	if (list_piece->next == NULL)
	{
				printf("Piece suivante exit pas\n");
		return (0);
	}
	else
	{
				printf("Piece suivante existe\n");
		return (1);
	}
}

t_piece			*ft_put_the_piece_n_move_to_zero(t_piece **list_piece, int n)
{
	printf("ft_put_the_n_move to zero, n=%d\n", n);
	int			k;
	t_piece		*local_list;

	local_list = *list_piece;
	k = 0;
	while (k != n)
	{
		(*list_piece) = (*list_piece)->next;
		k++;
	}
	(*list_piece)->move.x = 0;
	(*list_piece)->move.y = 0;
	return (local_list);
}

void			ft_reset_move(t_piece **list_piece)
{
	printf("ft_reset move\n");
	t_piece		*local_lst;

	printf("affiche donee =%d\n", (*list_piece)->point[1].x);
	local_lst = *list_piece;
	while (*list_piece)
	{
		printf("aller\n");
		(*list_piece)->move.x = 0;
		(*list_piece)->move.y = 0;
		(*list_piece) = (*list_piece)->next;
	}
	printf("les bleu\n");
	*list_piece = local_lst;
	printf("affiche donee =%d\n", (*list_piece)->point[1].x);
}

int				ft_try_to_put_the_pieces(int size_map, t_piece **list_piece, int n)
{
	printf("try to put the pieces, n=%d\n", n);
	t_piece		**local_lst;

	local_lst = list_piece;
	
	printf("affiche donee =%d\n", (*list_piece)->point[1].x);
	if (ft_put_the_piece(local_lst, n, 0, size_map) == 1)
	{
	printf("Bonjour\n");	
		if (ft_piece_n_plus_one_exist(*local_lst, n))
		{
			n++;
	printf("affiche donee =%d\n", (*list_piece)->point[1].x);
			ft_try_to_put_the_pieces(size_map, local_lst, n);
		}
		else
		{
	printf("affiche donee =%d\n", (*list_piece)->point[1].x);
			return (1);
		}
	}
	else
	{
	printf("affiche donee =%d\n", (*list_piece)->point[1].x);
		ft_put_the_piece_n_move_to_zero(local_lst, n);
		if (n >= 1)
		{
	printf("affiche donee =%d\n", (*list_piece)->point[1].x);
			if (ft_put_the_piece(local_lst, n - 1, 1, size_map) == 1)
			{
	printf("affiche donee =%d\n", (*list_piece)->point[1].x);
				ft_try_to_put_the_pieces(size_map, local_lst, n);
			}
			else
			{
	printf("affiche donee =%d\n", (*list_piece)->point[1].x);
				ft_reset_move(local_lst);
				n = 0;
				size_map = size_map + 1;
				//if (size_map == 5)
				//	exit(0);
				printf("on augmente la map a =%d\n", size_map);
				ft_try_to_put_the_pieces(size_map, local_lst, n);
			}
		}
		else
		{
	printf("affiche donee =%d\n", (*list_piece)->point[1].x);
			ft_reset_move(local_lst);
	printf("affiche donee =%d\n", (*list_piece)->point[1].x);
			n = 0;
			size_map = size_map + 1;
			//	if (size_map == 5)
			//		exit(0);
			printf("on augmente la map a =%d\n", size_map);
			ft_try_to_put_the_pieces(size_map, local_lst, n);
		}
	}
return (0);
}

int				main(int argc, char **argv)
{
	int			size_map;
	t_piece		*list_piece;
	int			toute_les_pieces_trouve;

	size_map = 1;
	list_piece = NULL;
	if (argc != 2)
	{
		ft_putstr("voici mon usage = il te faut 1 seul fichier l'ami\n");
		return (0);
	}
	if (!(ft_test_the_map(&list_piece, argv[1])))
	{
		ft_putstr("error\n");
		return (1);
	}
	ft_display_pieces(list_piece);
	list_piece = ft_translate_piece_origin(&list_piece);
	printf("translate done\n");
	ft_display_pieces(list_piece);
	printf("on place les pieces\n");
	ft_try_to_put_the_pieces(size_map, &list_piece, 0);
	printf("piece place\n");
	ft_display_pieces(list_piece);
	return (0);
}
