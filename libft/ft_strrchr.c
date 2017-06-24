/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:01:28 by tcuer             #+#    #+#             */
/*   Updated: 2014/11/11 15:05:32 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;
	char			*src;

	src = (char *)s;
	cc = c;
	i = ft_strlen(s);
	while (*src)
		src++;
	while (i-- > 0 && *src != cc)
		src--;
	if (*src == cc)
		return (src);
	return (NULL);
}
