/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:15:25 by tcuer             #+#    #+#             */
/*   Updated: 2016/09/19 15:30:17 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	char	*src;

	src = (char *)s;
	cc = c;
	while (*src != cc && *src)
		src++;
	if (*src == cc)
		return (src);
	return (NULL);
}
