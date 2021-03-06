/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 03:54:19 by kacoulib          #+#    #+#             */
/*   Updated: 2017/09/02 03:54:29 by kacoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_freejoin(char *s1, char const *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	if (!(tmp = ft_strjoin(s1, s2)))
		return (NULL);
	if (s1)
		free(s1);
	s1 = NULL;
	return (tmp);
}
