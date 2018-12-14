/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tetriminos.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:23:17 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/14 15:52:52 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  TEST_TETRIMINOS_H
# define TEST_TETRIMINOS_H

# include <stdio.h>
# include <fcntl.h>
# include "./gnl/jchardin/get_next_line.h"
# include "./libft/libft.h"


typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct      s_piece
{
    t_point         *point;             
    struct s_piece  *next;
}                   t_piece;

typedef struct      s_compteur
{
    int             i;
    int             j;
    int             k;
}                   t_compteur;


int                 ft_test_the_map(t_piece **list_piece, char  *filename);
int					ft_open_map(int *fd, char *filename);
int					ft_test_1(int fd);
int					ft_test_2(int fd);
int					ft_test_3(int fd);








int					ft_coordonate_piece(int fd, t_piece **list_piece);
t_piece				*ft_display_coordonee(t_piece *elem);
struct s_piece      *ft_lst_new_piece(t_piece *new_node);
void                ft_lst_add(t_piece **lst, t_piece *new_node);
void                ft_display_lst_piece(t_piece *lst);
int                 ft_check_for_contact(t_piece *lst);
int                 ft_translate_piece_to_origin(t_piece **list_piece);
int                 ft_test_tetriminos(t_piece **list_piece);

#endif
