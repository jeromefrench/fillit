/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:19:22 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/15 13:02:09 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_tetriminos.h"

/*
ft_try_to_put_the_pieces( piece, map)
{
   
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
}
*/


int		main(int argc, char **argv)
{
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
    //ft_test_tetriminos(&list_piece);
    //ft_translate_piece_to_origin(&list_piece);
    //ft_try_to_put_the_pieces();
    return (0);
}
