/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:38:34 by tcuer             #+#    #+#             */
/*   Updated: 2016/10/04 15:26:26 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 1000
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <math.h>
# define ENDL '\n'

typedef struct		s_tab
{
	int		*x;
	int		x1;
	int		x2;
	double	x3;
	double	dx;
	double	tmpx;
	int		*y;
	int		y1;
	int		y2;
	double	y3;
	double	dy;
	double	tmpy;
	int		*z;
	int		z2;
	double	*x3d;
	double	*y3d;
	int		i;
	int		j;
}					t_tab;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				**map;
	char			*file;
	int				*size;
	double			cte;
	int				x;
	int				y;
	double			x4;
	double			y4;
	int				x2;
	int				y2;
	t_tab			*tab;
	int				*range;
}					t_env;

typedef	struct		s_img
{

	int				bits;
	int				size;
	int				endian;
	char			*info;
}					t_img;

int					get_next_line(int const fd, char **line);
int					ft_getfullsize(int fd);
int					*ft_getsize(int fd, char *file);
int					**ft_getmap(int fd, t_env *e);
void				ft_draw(t_env *e);
void				mlx_pixel_img(void *img, int x, int y, int color);
void				ft_calcul(t_env *e);
void				ft_coord(t_env *e);
void				ft_trace(t_env *e, t_tab *tab);
void				ft_condition(t_env *e, t_tab *tab, int a);
unsigned int		ft_getcolor(t_env *e, t_tab *tab);
void				ft_move(t_env *e, char c, char c2);
void				ft_adjust(t_env *e);
void				ft_range(t_env *e);
int					ft_check(char *line);
#endif
