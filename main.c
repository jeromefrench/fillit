/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:19:22 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/15 17:02:14 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_tetriminos.h"

int				ft_put_the_piece(t_piece **list_piece, int n, t_point move, int size_map)
{
	printf("aij acces =%d\n", (*list_piece)->point[0].x);
	return (1);
}

void			ft_try_to_put_the_pieces(int size_map, t_piece **list_piece) //piece map
{

	t_point		move;
	int			n;

	size_map = 1;
	n = 0;
	move.x = 0;
	move.y = 0;
	ft_put_the_piece(list_piece, n = 0, move, size_map); 
	
	/*
	   if (put_the_piece(n) == 1)
	   {
	   if (piece n + 1 exist)
	   ft_try_to_put_the_piece(n + 1, map);
	   else
	   return (1);
	   }
	   else 
	   {
	   if (put_the_piece (n-1)(next-zone) == 1)
	   {
	   ft_try_to_put_the_piece(n);
	   }
	   else
	   {
	   ft_try_to_put_the_piece(piece = 0, map = map + 1)
	   }
	   }
	*/
}


int		main(int argc, char **argv)
{
	int			size_map;
	t_piece		*list_piece;
	int			toute_les_pieces_trouve;

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
	ft_try_to_put_the_pieces(size_map, &list_piece);
	return (0);
}
