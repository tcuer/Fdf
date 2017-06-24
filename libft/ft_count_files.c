/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 11:50:42 by tcuer             #+#    #+#             */
/*   Updated: 2015/03/27 11:52:59 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_files(DIR *dir)
{
	int				nbr;
	struct dirent	*ent;

	nbr = 0;
	ent = NULL;
	while ((ent = readdir(dir)) != NULL)
		if (ent->d_name[0] != '.')
			nbr++;
	return (nbr);
}
