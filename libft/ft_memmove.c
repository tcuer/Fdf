/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:07:02 by tcuer             #+#    #+#             */
/*   Updated: 2014/11/11 13:25:28 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char				*src1;
	char				*dst1;
	unsigned int		i;

	src1 = (char *)src;
	dst1 = dst;
	i = len;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	while (len > 0)
	{
		i--;
		dst1[i] = src1[i];
		len--;
	}
	return (dst);
}
