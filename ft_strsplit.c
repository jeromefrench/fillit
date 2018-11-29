/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:34:10 by jchardin          #+#    #+#             */
/*   Updated: 2018/11/29 16:31:42 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		word;
	char	**str;
	int		letter;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
				i++;
		if (s[i] != '\0')
		{
		while (s[i] != c && s[i] != '\0')
			i++;
		word++;
		}
	}
	if (!(str = (char**)malloc(sizeof(char*) * word + 1)))
		return (0);

	i = 0;
	j = 0;
	while (i < word)
	{
		j = 0;
		letter = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c)
		{
			j++;
			letter++;
		}
		if (!(str[i] = (char*)malloc(sizeof(char) * letter + 1)))
			return (0);
		i++;
	}

	i = 0;
	j = 0;
	while (j < word)
	{
		while (s[i] == c)
				i++;
		letter = 0;
		while (s[i] != c)
		{
			str[j][letter] = s[i];
			i++;
			letter++;
		}
			
			
		j++;
	}
	str[j] = 0;
	return (str);



}
