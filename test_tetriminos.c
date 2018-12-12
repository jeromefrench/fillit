/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:00:01 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/12 15:20:17 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_tetriminos.h"

int		main(void)
{
    int		fd;
    t_piece	*list_piece;

    list_piece = NULL;

    ft_putstr("CHECKING THE MAP\n\n");
    //------------------------------------------------------------
    ft_putstr("test1 CHECKING LINES LENGTH ->");
    ft_open_map(&fd);
    if (!ft_test_1(fd))
    {
        ft_putstr("Error in line length\n");
        return (1);
    }
    if (close(fd) == -1)
        return (1);
    //-------------------------------------------------------------
    ft_putstr("test2 CHECKING TETRIMINOS CONTENT 4 # -> ");
    ft_open_map(&fd);
    if (!(ft_test_2(fd)))
    {
        ft_putstr("Error in Tetriminos\n");
        return (1);
    }
    if (close(fd) == -1)
        return (1);
    //-------------------------------------------------------------
    ft_putstr("test3 CHECKING MAP CONTENT ONLY # AND . ->");
    ft_open_map(&fd);
    if (!(ft_test_3(fd)))
    {
        ft_putstr("Error map must content only # and .\n");
        return (1);
    }
    if (close(fd) == -1)
        return (1);
    //------------------------------------------------------------
    ft_putstr("CHECKING IF EACH BLOCK IS IN CONTACT WITH AN OTHER");
    ft_open_map(&fd);
    ft_coordonate_piece(fd, &list_piece);
    ft_display_lst_piece(list_piece);


    return (0);
}

int		ft_coordonate_piece(int fd, t_piece **list_piece)
{
    char			*line;
    int				i;
    int				j;
    int				k;
    t_piece			*new_node;

    i = 0;
    k = 0;
    while (get_next_line(fd, &line) > 0)
    {

        i = i % 4;
        if (i == 0)
        {
            printf("\nJe fais un new node\n");
            new_node = ft_lst_new_piece(new_node);
        }
        if (ft_strlen(line) > 0)
        {
            //printf("La ligne =%s\n", line);
            j = 0;
            while(line[j] != '\0')
            {
                if (line[j] == '#')
                {
                    new_node->point[k].x = i;
                    new_node->point[k].y = j;
                    //printf("Le k =%d Le x =%d Le y =%d\n", k, i, j);
                    k++;
                }
                j++;
            }
            i++;
        }
        if (k == 4)
        {
            //printf("Une coordonee =%d et le next= %p", new_node->point[2].x, new_node->next);
            k = 0;
            //printf("\n\n\n");
            ft_lst_add(list_piece, new_node);
            printf("Une coordonee =%d et le next= %p\n", new_node->point[2].x, new_node->next);
            printf("Pointeur new node= %p\n", new_node);
            printf("L'adresse de lst= %p\n", *list_piece);
        }
    }
    return (1);
}

void	ft_test_4(void)
{
    return ;
}

int		ft_open_map(int *fd)
{
    if ((*fd = open("sample.fillit", O_RDONLY)) == -1)
    {
        printf("file descriptor failure");
        return (1);
    }
    return (0);
}

int		ft_test_1(int fd)
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

int		ft_test_2(int fd)
{
    int		i;
    int		j;
    char	*line;
    char	buff;
    int		ret;

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

int		ft_test_3(int fd)
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
