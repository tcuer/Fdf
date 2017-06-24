/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 11:31:47 by tcuer             #+#    #+#             */
/*   Updated: 2015/03/27 11:53:54 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	whilex(t_draw d, t_env *e)
{
	int		i;

	i = 0;
	d.x = d.tmpx;
	d.y = d.tmpy;
	if (d.x < d.x2)
		while (d.x < d.x2)
		{
			d.y = (int)((double)d.tmpy - (double)d.dy *
					((double)d.tmpx - (double)d.x) / (double)d.dx);
			mlx_pixel_put(e->mlx, e->win, d.x, d.y, 0x0000FF);
			d.x++;
			i++;
		}
	if (d.x2 < d.x)
	{
		while (d.x2 < d.x)
		{
			d.y = (int)((double)d.tmpy - (double)d.dy *
					((double)d.tmpx - (double)d.x2) / (double)d.dx);
			mlx_pixel_put(e->mlx, e->win, d.x2, d.y, 0x0000FF);
			d.x2++;
			i++;
		}
	}
}

void		ft_lines(t_env *e, t_draw d)
{
	d.tmpx = d.x1;
	d.tmpy = d.y1;
	d.dx = d.x2 - d.x1;
	d.dy = d.y2 - d.y1;
	whilex(d, e);
}
