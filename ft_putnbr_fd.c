/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:45:04 by jchardin          #+#    #+#             */
/*   Updated: 2018/11/29 16:52:29 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gere le max min

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if(n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if(n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd( (n % 10) + '0', fd);
}
