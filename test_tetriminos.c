/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:00:01 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/15 16:37:47 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_tetriminos.h"

static int		ft_test_line_length(int *fd, char *filename)
{
	ft_putstr("test1 CHECKING LINES LENGTH = 4 then 0->");
	if (!(ft_open_map(fd, filename)))
		return (0);
	if (!ft_test_1(*fd))
	{
		ft_putstr("Error in line length\n");
		return (0);
	}
	if (close(*fd) == -1)
		return (0);
	return (1);
}

static int		ft_test_tetriminos_content(int *fd, char *filename)
{
	ft_putstr("test2 CHECKING TETRIMINOS CONTENT ONLY 4 # -> ");
	if (!(ft_open_map(fd, filename)))
		return (0);
	if (!(ft_test_2(*fd)))
	{
		ft_putstr("Error in Tetriminos\n");
		return (0);
	}
	if (close(*fd) == -1)
		return (0);
	return (1);
}

static int		ft_checkind_map_content_dot_dash(int *fd, char *filename)
{
	ft_putstr("test3 CHECKING MAP CONTENT ONLY # AND . ->");
	if (!(ft_open_map(fd, filename)))
		return (0);
	if (!(ft_test_3(*fd)))
	{
		ft_putstr("Error map must content only # and .\n");
		return (0);
	}
	if (close(*fd) == -1)
		return (0);
	return (1);
}

static int		ft_check_for_valid_tetriminos(int *fd,
char *filename, t_piece **list_piece)
{
	ft_putstr("test4 CHECKING IF EACH BLOCK IS IN CONTACT WITH AN OTHER ->");
	if (!(ft_open_map(fd, filename)))
		return (0);
	ft_coordonate_piece(*fd, list_piece);
	if (!(ft_check_for_contact(*list_piece)))
	{
		ft_putstr("Error in a block not connected to an other\n");
		return (0);
	}
	if (close(*fd) == -1)
		return (0);
	ft_putstr(" OK\n");
	return (1);
}

int				ft_test_the_map(t_piece **list_piece, char *filename)
{
	int		fd;

	*list_piece = NULL;
	ft_putstr("CHECKING THE MAP\n\n");
	if (!(ft_test_line_length(&fd, filename)))
		return (0);
	if (!(ft_test_tetriminos_content(&fd, filename)))
		return (0);
	if (!(ft_checkind_map_content_dot_dash(&fd, filename)))
		return (0);
	if (!(ft_check_for_valid_tetriminos(&fd, filename, list_piece)))
		return (0);
	return (1);
}

void			ft_coordonate_piece_decoupe(t_compteur *count,
t_piece **new_node, char *line, t_piece **list_piece)
{
	if (count->i == 0)
		*new_node = ft_lst_new_piece(*new_node);
	if (ft_strlen(line) > 0)
	{
		count->j = 0;
		while (line[count->j] != '\0')
		{
			if (line[count->j] == '#')
			{
				(*new_node)->point[count->k].x = count->j;
				(*new_node)->point[count->k].y = count->i;
				count->k++;
			}
			count->j++;
		}
		count->i++;
	}
	if (count->k == 4)
	{
		count->k = 0;
		ft_lst_add(list_piece, *new_node);
	}
}

int				ft_coordonate_piece(int fd, t_piece **list_piece)
{
	char			*line;
	t_compteur		*count;
	t_piece			*new_node;

	count = malloc(sizeof(t_compteur));
	count->i = 0;
	count->k = 0;
	while (get_next_line(fd, &line) > 0)
	{
		count->i = count->i % 4;
		ft_coordonate_piece_decoupe(count, &new_node, line, list_piece);
	}
	return (1);
}

int				ft_open_map(int *fd, char *filename)
{
	if ((*fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("file descriptor failure");
		return (0);
	}
	return (1);
}

int				ft_test_1(int fd)
{
	int		i;
	char	*line;

	i = -1;
	while (get_next_line(fd, &line))
	{
		if (++i < 4)
			if ((int)ft_strlen(line) != 4)
				return (0);
		if (i == 4)
		{
			if ((int)ft_strlen(line) != 0)
				return (0);
			i = -1;
		}
	}
	ft_putstr(" OK\n");
	return (1);
}

int				ft_test_2(int fd)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) != 0)
		{
			i = -1;
			while (line[++i] != '\0')
			{
				if (line[i] == '#')
					j++;
			}
		}
		else
		{
			if (j != 4)
				return (0);
			j = 0;
		}
	}
	ft_putstr(" OK\n");
	return (1);
}

int				ft_test_3(int fd)
{
	char	*line;
	int		i;

	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] != '#' && line[i] != '.')
				return (0);
			i++;
		}
	}
	ft_putstr(" OK\n");
	return (1);
}
