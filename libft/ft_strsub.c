/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 10:21:06 by tcuer             #+#    #+#             */
/*   Updated: 2014/11/13 11:37:44 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	dst = ft_strnew(len + 1);
	if (dst == NULL)
		return (NULL);
	while (i < len + start)
	{
		if (i + 1 > start)
		{
			dst[i - start] = s[i];
		}
		i++;
	}
	return (dst);
}
