/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:15:15 by tcuer             #+#    #+#             */
/*   Updated: 2014/11/13 10:20:46 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*dst;
	size_t			i;

	i = 0;
	dst = ft_strdup(s);
	if (dst == '\0')
		return (NULL);
	while (dst[i])
	{
		dst[i] = f(s[i]);
		i++;
	}
	return (dst);
}
