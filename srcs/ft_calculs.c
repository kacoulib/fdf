/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 21:19:44 by kacoulib          #+#    #+#             */
/*   Updated: 2017/10/01 21:19:47 by kacoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_draw		init(t_point d1, t_point d2)
{
	t_draw			ret;

	ret.dx = abs(d2.real_x - d1.real_x);
	ret.sx = d1.real_x < d2.real_x ? 1 : -1;
	ret.dy = abs(d2.real_y - d1.real_y);
	ret.sy = d1.real_y < d2.real_y ? 1 : -1;
	ret.err = (ret.dx > ret.dy ? ret.dx : -ret.dy) / 2;
	ret.e2 = 0;
	return (ret);
}

static void			line(t_master *data, t_point d1, t_point d2)
{
	t_draw			tmp;

	tmp = init(d1, d2);
	while (1)
	{
		mlx_pixel_put(data->mlx, data->window, d1.real_x, d1.real_y, 0xFF0000);
		if (d1.real_x == d2.real_x && d1.real_y == d2.real_y)
			break ;
		tmp.e2 = tmp.err;
		if (tmp.e2 > -tmp.dx)
		{
			tmp.err -= tmp.dy;
			d1.real_x += tmp.sx;
		}
		if (tmp.e2 < tmp.dy)
		{
			tmp.err += tmp.dx;
			d1.real_y += tmp.sy;
		}
	}
}

static void			match_dot(t_master *data, t_point dot1, t_point dot2)
{
	line(data, dot1, dot2);
}

static void			last_line(t_master *s, t_point *dot, int l)
{
	int				x;

	x = 0;
	while (x < l - 1)
	{
		match_dot(s, dot[x], dot[x + 1]);
		x++;
	}
}

void				print_map(t_master *info, t_point **data)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	last_line(info, data[(info->endl) - 1], info->len);
	while (x < info->endl - 1)
	{
		y = 0;
		while (y < info->len)
		{
			match_dot(info, data[x][y], data[x + 1][y]);
			if (y < info->len - 1)
				match_dot(info, data[x][y], data[x][y + 1]);
			y++;
		}
		x++;
	}
}
