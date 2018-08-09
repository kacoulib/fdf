/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:33:03 by kacoulib          #+#    #+#             */
/*   Updated: 2017/09/29 03:18:14 by kacoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	if (!(r = ft_memalloc(i)))
		return (NULL);
	ft_bzero(r, i);
	ft_strcpy(r, s1);
	ft_strcat(r, s2);
	return (r);
}
