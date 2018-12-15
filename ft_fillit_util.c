/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:35:06 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/15 14:04:15 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_tetriminos.h"

int				ft_give_size_map(t_piece *list_piece)
{
	int		max;
	int		i;

	max = 0;
	while (list_piece != NULL)
	{
		i = 0;
		while (i < 4)
		{
			if (list_piece->point[i].x > max)
				max = list_piece->point[i].x;
			if (list_piece->point[i].y > max)
				max = list_piece->point[i].y;
			i++;
		}
		list_piece = list_piece->next;
	}
	return (max);
}

char			**ft_mallcage_de_display(char **piece, t_piece *list_piece, int *size)
{
	int		i;

	*size = 0;
	if ((*size = ft_give_size_map(list_piece)) <= 3)
		*size = 3;
	piece = (char**)malloc(sizeof(char*) * (*size + 2));
	i = -1;
	while (++i < *size + 2)
		piece[i] = (char*)malloc(sizeof(char) * (*size + 2));
	return (piece);
}

void			ft_display_decoupe(int *size, char **piece, int *k, t_piece *list_piece)
{
	int		i;
	int		j;

	i = 0;
	while (i < *size + 1)
	{
		j = 0;
		while (j < *size + 2)
		{
			piece[i][j] = '.';
			if (j == *size + 1)
				piece[i][j] = '\0';
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < *size + 1)
		piece[list_piece->point[i].x][list_piece->point[i].y] = 'A' + *k;
	i = -1;
	while (++i < *size + 1)
		printf("=%s\n", piece[i]);
}

int				ft_display_pieces(t_piece *list_piece)
{
	int		i;
	int		j;
	int		k;
	char	**piece;
	int		size;

	piece = ft_mallcage_de_display(piece, list_piece, &size);
	printf("On affiche les pieces\n");
	k = -1;
	while (list_piece != NULL)
	{
		k++;
		ft_display_decoupe(&size, piece, &k, list_piece);
		list_piece = list_piece->next;
		printf("\n\n");
	}
	return (1);
}

int				ft_translate_piece_origin(t_piece *list_piece)
{
	int		i;
	int		y;
	int		x;

	i = 0;
	/* while (list_piece)
	   {
	   printf("\n\nLa piece n %d\n", i);
	   i++;
	   y = 0;
	   while (y < 4)
	   {
	//printf("La coordonee n %d\n", y);
	//printf("X=%d   Y=%d\n", list_piece->point[y].x, list_piece->point[y].y);
	y++;
	}
	list_piece = list_piece->next;
	}
	*/
	//on y axe
	i = 0;
	while (list_piece)
	{
		x = list_piece->point[0].x;
		printf("Le x =%d\n", x);
		i = 0;
		while (i < 4)
		{
			printf("AAAA\n");
			list_piece->point[i].x -= x;
			i++;
		}
		list_piece = list_piece->next;
	}
	return (1);
}

int				ft_translate_piece_to_origin(t_piece **list_piece)
{
	int		fd;

	(void)list_piece;
	ft_display_pieces(*list_piece);
	ft_putstr("TRANSLATE PIECE\n\n");
	//------------------------------------------------------------
	//    ft_open_map(&fd);
	if (!ft_translate_piece_origin(*list_piece))
	{
		ft_putstr("Error in line length\n");
		return (1);
	}
	if (close(fd) == -1)
		return (1);
	ft_display_pieces(*list_piece);
	return (1);
}
