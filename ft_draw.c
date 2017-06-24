/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 11:20:30 by tcuer             #+#    #+#             */
/*   Updated: 2016/10/04 14:25:36 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_pixel_img(void *img, int x, int y, int color)
{
	int		i;
	t_img	pxl;

	pxl.info = mlx_get_data_addr(img, &pxl.bits, &pxl.size, &pxl.endian);
	i = x * 4 + y * pxl.size;
	pxl.info[i] = color % 256;
	color /= 256;
	pxl.info[i + 1] = color % 256;
	color /= 256;
	pxl.info[i + 2] = color % 256;
	color /= 256;
	pxl.info[i + 3] = 0;
	color /= 256;
}

void	ft_coord(t_env *e)
{
	int		i;
	int		j;

	e->tab = (t_tab *)malloc(sizeof(t_tab) * e->size[0] * e->size[1]);
	e->tab->z = (int *)malloc(sizeof(int) * e->size[0] * e->size[1]);
	e->tab->x = (int *)malloc(sizeof(int) * e->size[0] * e->size[1]);
	e->tab->y = (int *)malloc(sizeof(int) * e->size[0] * e->size[1]);
	i = 0;
	j = 0;
	while (i < e->size[0])
	{
		e->tab[i].z = (int *)malloc(sizeof(int) * e->size[0] * e->size[1]);
		e->tab[i].x = (int *)malloc(sizeof(int) * e->size[0] * e->size[1]);
		e->tab[i].y = (int *)malloc(sizeof(int) * e->size[0] * e->size[1]);
		while (j < e->size[1])
		{
			e->tab[i].z[j] = e->map[i][j];
			e->tab[i].x[j] = j;
			e->tab[i].y[j] = i;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_trace(t_env *e, t_tab *tab)
{
	if (tab->x3 < tab->x2)
	{
		while (tab->x3 < tab->x2)
		{
			tab->y3 = (tab->tmpy - tab->dy *
					(tab->tmpx - tab->x3) / tab->dx);
			mlx_pixel_img(e->img, tab->x3, tab->y3, ft_getcolor(e, tab));
			tab->x3++;
		}
	}
	if (tab->x2 < tab->x3)
	{
		while (tab->x2 < tab->x3)
		{
			tab->y3 = (tab->tmpy - tab->dy *
					(tab->tmpx - tab->x2) / tab->dx);
			mlx_pixel_img(e->img, tab->x2, tab->y3, ft_getcolor(e, tab));
			tab->x2++;
		}
	}
}

void	ft_condition(t_env *e, t_tab *tab, int a)
{
	tab->x1 = tab[e->tab->i].x3d[e->tab->j];
	tab->y1 = tab[e->tab->i].y3d[e->tab->j];
	tab->x2 = tab[e->tab->i].x3d[e->tab->j];
	tab->y2 = tab[e->tab->i].y3d[e->tab->j];
	if (e->tab->j < e->size[1] - 1 && a == 1)
	{
		tab->x2 = tab[e->tab->i].x3d[e->tab->j + 1];
		tab->y2 = tab[e->tab->i].y3d[e->tab->j + 1];
	}
	if (e->tab->i < e->size[0] - 1 && a == 2)
	{
		tab->x2 = tab[e->tab->i + 1].x3d[e->tab->j];
		tab->y2 = tab[e->tab->i + 1].y3d[e->tab->j];
	}
	tab->tmpx = tab->x1;
	tab->tmpy = tab->y1;
	tab->dx = tab->x2 - tab->x1;
	tab->dy = tab->y2 - tab->y1;
	tab->x3 = tab->tmpx;
	tab->y3 = tab->tmpy;
	ft_trace(e, tab);
}

void	ft_draw(t_env *e)
{
	ft_calcul(e);
	e->tab->i = 0;
	e->tab->j = 0;
	e->img = mlx_new_image(e->mlx, e->x2 * 5, e->y2 * 5);
	while (e->tab->i < e->size[0])
	{
		while (e->tab->j < e->size[1])
		{
			ft_condition(e, e->tab, 1);
			ft_condition(e, e->tab, 2);
			e->tab->j++;
		}
		e->tab->i++;
		e->tab->j = 0;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
