/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 11:46:17 by tcuer             #+#    #+#             */
/*   Updated: 2015/03/27 11:47:07 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_calcul_3d(t_tab *tab, int *length, t_env *e)
{
	unsigned int	i;
	unsigned int	size;
	double			cte;

	cte = e->x;
	i = -1;
	size = length[0] * length[1];
	e->color = (int *)malloc(sizeof(int) * size);
	while (++i < size)
	{
		tab[i].x3d = (cte * tab[i].x - cte * tab[i].y) + 500;
		tab[i].y3d = (tab[i].z * -1 + (cte / 2.0) *
				tab[i].x + (cte / 2.0) * tab[i].y) + 300;
	}
	i = 0;
}
