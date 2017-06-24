/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:41:15 by tcuer             #+#    #+#             */
/*   Updated: 2016/10/04 16:00:58 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_range(t_env *e)
{
	int		i;
	int		j;

	e->range = (int *)malloc(sizeof(int) * 2);
	i = -1;
	j = -1;
	e->range[0] = 0;
	e->range[1] = 0;
	while (++i < e->size[0])
	{
		while (++j < e->size[1])
		{
			if (e->map[i][j] <= e->range[0])
				e->range[0] = e->map[i][j];
			if (e->map[i][j] >= e->range[1])
				e->range[1] = e->map[i][j];
		}
		j = -1;
	}
}

int				ft_check(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '-' &&
				(line[i] < '0' || line[i] > '9'))
		{
			ft_putendl("Wrong type of map");
			exit(0);
		}
		i++;
	}
	return (0);
}
