/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:02:29 by tcuer             #+#    #+#             */
/*   Updated: 2015/03/26 14:43:09 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	char		*s;
	size_t		j;
	size_t		c;

	c = 0;
	j = 0;
	i = 0;
	s = (char *)s1;
	if (ft_strlen(s2) == 0)
		return (s);
	while (i < n && s1[i] != '\0')
	{
		j = i;
		c = 0;
		while (s1[j] == s2[c] && j < n)
		{
			j++;
			c++;
			if (s2[c] == '\0')
				return (char*)(&s1[i]);
		}
		i++;
	}
	return (NULL);
}
