/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 10:10:04 by tcuer             #+#    #+#             */
/*   Updated: 2014/11/13 10:25:11 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t		i;
	char		*dst;

	i = 0;
	dst = ft_strdup(s);
	if (dst == '\0')
		return (NULL);
	while (dst[i])
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	return (dst);
}
