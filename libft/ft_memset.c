/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:39:39 by tcuer             #+#    #+#             */
/*   Updated: 2014/11/12 11:30:48 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*bb;
	unsigned char	cc;

	i = 0;
	bb = b;
	cc = c;
	while (len > i)
	{
		bb[i] = cc;
		i++;
	}
	return (bb);
}
