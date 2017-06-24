/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 11:35:02 by tcuer             #+#    #+#             */
/*   Updated: 2015/03/27 11:47:19 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(int argc, int fd)
{
	if (argc == 1)
	{
		ft_putstr("File is missing\n");
		exit(0);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments\n");
		exit(0);
	}
	if (fd == -1)
	{
		ft_putstr("No such file\n");
		exit(0);
	}
}
