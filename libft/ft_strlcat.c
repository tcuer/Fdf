/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:28:58 by tcuer             #+#    #+#             */
/*   Updated: 2014/11/13 10:23:38 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			length;
	size_t			tmp1;
	size_t			tmp2;

	tmp1 = ft_strlen(dst);
	tmp2 = ft_strlen(src);
	length = size;
	while (*dst && size)
	{
		dst++;
		size--;
	}
	if (!size)
		return (length + tmp2);
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (tmp1 + tmp2);
}
