/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:35:06 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/15 17:00:57 by jchardin         ###   ########.fr       */
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

char			**ft_mallcage_de_display(char **piece,
t_piece *list_piece, int *size)
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

void			ft_display_decoupe(int *size, char **piece,
int *k, t_piece *list_piece)
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
		piece[list_piece->point[i].y][list_piece->point[i].x] = 'A' + *k;
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

void			ft_translate_piece_decoupe(t_piece **list_piece,
int *xmin, int *ymin)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if ((*list_piece)->point[j].x < *xmin)
			*xmin = (*list_piece)->point[j].x;
		if ((*list_piece)->point[j].y < *ymin)
			*ymin = (*list_piece)->point[j].y;
		j++;
	}
	j = 0;
	while (j < 4)
	{
		(*list_piece)->point[j].x = (*list_piece)->point[j].x - *xmin;
		(*list_piece)->point[j].y = (*list_piece)->point[j].y - *ymin;
		j++;
	}
}

t_piece			*ft_translate_piece_origin(t_piece **list_piece)
{
	int			i;
	int			xmin;
	int			ymin;
	t_piece		*lst_origin;

	lst_origin = *list_piece;
	while (*list_piece)
	{
		ymin = (*list_piece)->point[0].y;
		xmin = (*list_piece)->point[0].x;
		ft_translate_piece_decoupe(list_piece, &xmin, &ymin);
		*list_piece = (*list_piece)->next;
	}
	return (lst_origin);
}
