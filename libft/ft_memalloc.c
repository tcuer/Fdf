/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:24:26 by tcuer             #+#    #+#             */
/*   Updated: 2014/11/12 11:52:57 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char			*fraiche;
	unsigned int	i;

	i = 0;
	fraiche = (char *)malloc(sizeof(char) * size);
	if (fraiche == NULL)
		return (NULL);
	while (i < size)
	{
		fraiche[i] = '\0';
		i++;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
