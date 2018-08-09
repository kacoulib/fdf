/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 21:18:32 by kacoulib          #+#    #+#             */
/*   Updated: 2017/10/01 21:18:35 by kacoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDHT 1920
# define HEIGHT 1280
# define INIT_X 490
# define INIT_Y 100
# define SUB_WIDTH 1200
# define SUB_HEIGHT 560
# define ESC 53

typedef struct		s_stock
{
	int				len;
	int				endl;
	char			**data;
}					t_stock;

typedef struct		s_draw
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_draw;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				real_x;
	int				real_y;
}					t_point;

typedef struct		s_master
{
	void			*mlx;
	void			*window;
	int				endl;
	int				len;
	t_point			**data;
}					t_master;

char				**ft_parsing(char *file, int endl);
int					size_line(char *str);
int					ft_count_line(char *file);
t_point				**ft_get_data(char **data, int len, int endl);
void				print_map(t_master *info, t_point **data);

#endif
