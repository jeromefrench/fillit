/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:35:51 by jchardin          #+#    #+#             */
/*   Updated: 2018/11/29 15:25:14 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	int		i;

	if (!(mem = (char*)malloc(size)))
		return (0);
	i = 0;
	while (i < size)
	{
		*(mem + i) = 0;
		i++;
	}
	return (mem);
}
