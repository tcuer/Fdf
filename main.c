/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:35:12 by tcuer             #+#    #+#             */
/*   Updated: 2016/10/04 15:47:01 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_move(t_env *e, char c, char c2)
{
	if (c2 == 'x')
	{
		if (c == '+')
			e->x += 50;
		if (c == '-')
			e->x -= 50;
	}
	if (c2 == 'y')
	{
		if (c == '+')
			e->y += 50;
		if (c == '-')
			e->y -= 50;
	}
}

int			expose_hook(t_env *e)
{
	mlx_do_sync(e->mlx);
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		e->cte += 5;
	if (keycode == 78)
	{
		if (e->cte > 0)
			e->cte -= 5;
	}
	if (keycode == 124)
		ft_move(e, '+', 'x');
	if (keycode == 123)
		ft_move(e, '-', 'x');
	if (keycode == 125)
		ft_move(e, '+', 'y');
	if (keycode == 126)
		ft_move(e, '-', 'y');
	if (keycode == 91)
		e->y4 += 1;
	if (keycode == 84)
		e->y4 -= 1;
	ft_draw(e);
	return (0);
}

void		ft_adjust(t_env *e)
{
	int	size;

	size = e->size[0] * e->size[1];
	e->cte = 40;
	if (size > 100)
		e->cte = 30;
	if (size > 500)
		e->cte = 20;
	if (size > 1000)
		e->cte = 15;
	if (size > 2000)
		e->cte = 10;
	if (size > 5000)
		e->cte = 5;
	if (size > 10000)
		e->cte = 2;
	if (size > 100000)
		e->cte = 1.1;
}

int			main(int argc, char **argv)
{
	t_env	*e;
	int		fd;

	e = (t_env *)malloc(sizeof(t_env));
	fd = open(argv[1], O_RDONLY);
	ft_error(argc, fd);
	e->x = 500;
	e->y = 300;
	e->y4 = 1;
	e->file = argv[1];
	e->map = ft_getmap(fd, e);
	ft_range(e);
	ft_adjust(e);
	e->x2 = 1500;
	e->y2 = 1000;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1200, 800, "Fdf");
	ft_coord(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
