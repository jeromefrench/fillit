/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:56:54 by jchardin          #+#    #+#             */
/*   Updated: 2018/11/29 16:26:10 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*swap;
	char	*str;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(swap = malloc(sizeof(char) * i + 1)))
		return (0);
	while (s[i] == '\0' || s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
//		s[i] = '\0'; erreur assign
		i--;
	}
	i = 0;
	while (s[i] == '\0' || s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = 0;
	while (s[i] != '\0')
	{
		swap[j] = s[i];
		j++;
		i++;
	}
	swap[j] = '\0';
	while (swap[i] != '\0')
		i++;
	if (!(str = malloc(sizeof(char) * i + 1)))
			return (0);
	i = 0;
	while (swap[i] != '\0')
	{
		str[i] = swap[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
