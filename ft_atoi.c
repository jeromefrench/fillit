/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 08:09:21 by jchardin          #+#    #+#             */
/*   Updated: 2018/11/29 14:33:57 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		nega;

	i = 0;
	nega = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		nega = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * nega);
}
