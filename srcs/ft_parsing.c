/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 21:20:09 by kacoulib          #+#    #+#             */
/*   Updated: 2017/10/01 21:20:11 by kacoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_count_line(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (!fd || !file)
	{
		ft_putendl("open() error");
		exit(EXIT_FAILURE);
	}
	count = 0;
	while (get_next_line(fd, &line))
	{
		count++;
		free(line);
	}
	if (!count)
	{
		ft_putendl("empty map");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (count);
}

char		**ft_parsing(char *file, int endl)
{
	int		fd;
	char	**ret;
	char	*line;
	int		index;

	index = 0;
	fd = open(file, O_RDONLY);
	if (!(ret = (char**)malloc(sizeof(char*) * (endl + 1))))
	{
		ft_putendl("bad map");
		exit(EXIT_FAILURE);
	}
	while (index < endl && get_next_line(fd, &line))
	{
		ret[index] = ft_strdup(line);
		free(line);
		index++;
	}
	close(fd);
	return (ret);
}

int			size_line(char *str)
{
	int		cnt;
	int		in_substring;

	in_substring = 0;
	cnt = 0;
	while (*str != '\0')
	{
		if (in_substring == 1 && *str == ' ')
			in_substring = 0;
		if (in_substring == 0 && *str != ' ')
		{
			in_substring = 1;
			cnt++;
		}
		str++;
	}
	return (cnt);
}
