/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 21:19:57 by kacoulib          #+#    #+#             */
/*   Updated: 2017/10/01 21:20:00 by kacoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*ft_apply_f(char *line, int current_line, int len)
{
	char		**tmp;
	t_point		*ret;
	int			index;

	tmp = ft_strsplit(line, ' ');
	if (!(ret = (t_point*)malloc(sizeof(t_point) * (len + 1))))
		return (NULL);
	index = 0;
	while (index < len && *tmp)
	{
		ret[index].x = index;
		ret[index].y = current_line;
		ret[index].z = ft_atoi(*tmp);
		ret[index].real_x = INIT_X + ((SUB_WIDTH / (len - 1)) * ret[index].x)
			- (4 * ret[index].y);
		ret[index].real_y = INIT_Y + ((SUB_HEIGHT / (len - 1)) * ret[index].y) -
		(0.7 * ((SUB_HEIGHT / (len - 1)) * ret[index].z)) + (4 * ret[index].x);
		index++;
		tmp++;
	}
	ft_memdel((void*)tmp);
	free(line);
	return (ret);
}

t_point			**ft_get_data(char **data, int len, int endl)
{
	t_point		**ret;
	int			index;

	if (!(ret = (t_point**)malloc(sizeof(t_point*) * (endl + 1))))
		return (NULL);
	index = 0;
	while (index < endl)
	{
		ret[index] = ft_apply_f(*data, index, len);
		index++;
		data++;
	}
	ret[endl] = NULL;
	return (ret);
}
