/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:35:18 by tcuer             #+#    #+#             */
/*   Updated: 2015/03/26 12:09:20 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dst1;
	char			*src1;
	char			cc;

	cc = c;
	dst1 = dst;
	src1 = (char *)src;
	while (n > 0)
	{
		*dst1++ = *src1;
		if (*src1 == cc)
			return (dst1);
		src1++;
		n--;
	}
	return (NULL);
}
