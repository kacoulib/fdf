/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 21:20:21 by kacoulib          #+#    #+#             */
/*   Updated: 2017/10/01 21:20:25 by kacoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_calcul_len(char **data, int endl)
{
	int			ret;
	int			tmp;

	tmp = 0;
	ret = size_line(data[0]);
	while (tmp < endl)
	{
		if (size_line(data[tmp]) < ret)
		{
			ft_putendl("omg bad size line :(");
			exit(EXIT_FAILURE);
		}
		tmp++;
	}
	return (ret);
}

static void		init_data(t_master *data, char *file)
{
	char		**tmp;

	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIDHT, HEIGHT, "fdf");
	data->endl = ft_count_line(file);
	tmp = ft_parsing(file, data->endl);
	data->len = ft_calcul_len(tmp, data->endl);
	if (data->len <= 1)
	{
		ft_putendl("bad map");
		exit(EXIT_FAILURE);
	}
	data->data = ft_get_data(tmp, data->len, data->endl);
}

static int		my_function(int key, t_master *setup)
{
	if (key == ESC)
	{
		exit(0);
		ft_memdel((void*)setup);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_master	data;

	if (ac != 2)
	{
		ft_putendl("invalid nb of params !");
		exit(EXIT_FAILURE);
	}
	init_data(&data, av[1]);
	print_map(&data, data.data);
	mlx_hook(data.window, 2, 3, my_function, &data);
	mlx_loop(data.mlx);
	return (0);
}
