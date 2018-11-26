/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:46:44 by jchardin          #+#    #+#             */
/*   Updated: 2018/11/26 15:08:47 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int c)
{
		int		up;

		up = c;
		if (c <= 122 && c >= 97)
			up = c - 32;
		return (up);
}
