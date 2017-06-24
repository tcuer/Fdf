/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 12:50:53 by tcuer             #+#    #+#             */
/*   Updated: 2016/10/04 16:24:04 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_getcolor(t_env *e, t_tab *tab)
{
	int		retcolor;
	double	size;

	size = abs(e->range[0]) + abs(e->range[1]);
	size = size / 4;
	retcolor = mlx_get_color_value(e->mlx, 0xFF0000);
	if (tab[tab->i].z[tab->j] <= e->range[0] + size)
		retcolor = mlx_get_color_value(e->mlx, 0x0000FF);
	else if (tab[tab->i].z[tab->j] <= e->range[0] + size * 2)
		retcolor = mlx_get_color_value(e->mlx, 0x33FF00);
	else if (tab[tab->i].z[tab->j] <= e->range[0] + size * 3)
		retcolor = mlx_get_color_value(e->mlx, 0x663300);
	else if (tab[tab->i].z[tab->j] <= e->range[0] + size * 4)
		retcolor = mlx_get_color_value(e->mlx, 0xFFFFFF);
	return (retcolor);
}

void			ft_calcul(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	e->tab->x3d = (double *)malloc(sizeof(int) * e->size[0] * e->size[1]);
	e->tab->y3d = (double *)malloc(sizeof(int) * e->size[0] * e->size[1]);
	while (i < e->size[0])
	{
		e->tab[i].x3d = (double *)malloc(sizeof(int) * e->size[0] * e->size[1]);
		e->tab[i].y3d = (double *)malloc(sizeof(int) * e->size[0] * e->size[1]);
		while (j < e->size[1])
		{
			e->tab[i].x3d[j] = (e->cte * e->tab[i].x[j] -
					e->cte * e->tab[i].y[j]) + e->x;
			e->tab[i].y3d[j] = (e->tab[i].z[j] * e->y4 * -1 + (e->cte / 2) *
					e->tab[i].x[j] + (e->cte / 2) * e->tab[i].y[j]) + e->y;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
}

int				ft_getfullsize(int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		while (line[j] != '\0')
		{
			if (line[j] >= '0' && line[j] <= '9')
			{
				if (!(line[j + 1] >= '0' && line[j + 1] <= '9'))
				{
					i++;
				}
			}
			j++;
		}
		j = 0;
	}
	return (i);
}

int				*ft_getsize(int fd, char *file)
{
	int		*i;
	int		j;
	char	*line;

	i = (int *)malloc(sizeof(int) * 2);
	i[0] = 0;
	i[1] = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_check(line);
		if (i[1] == 0)
			while (line[j])
			{
				if (line[j] >= '0' && line[j] <= '9')
				{
					if (line[j + 1] == ' ' || line[j + 1] == '\0')
						i[1]++;
				}
				j++;
			}
		i[0]++;
	}
	return (i);
}

int				**ft_getmap(int fd, t_env *e)
{
	char	*line;
	char	**tab;
	int		j;
	int		i;
	int		**ret;

	e->size = ft_getsize(fd, e->file);
	fd = open(e->file, O_RDONLY);
	i = 0;
	j = 0;
	ret = (int **)malloc(sizeof(int *) * e->size[0] * e->size[1] + 1);
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		tab = ft_strsplit(line, ' ');
		ret[j] = (int *)malloc(sizeof(int) * e->size[0] * e->size[1] + 1);
		while (tab[i])
		{
			ret[j][i] = ft_atoi(tab[i]);
			i++;
		}
		j++;
		i = 0;
	}
	return (ret);
}
