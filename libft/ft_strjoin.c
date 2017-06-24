/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 11:34:10 by tcuer             #+#    #+#             */
/*   Updated: 2015/03/20 11:27:40 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*a;
	char	*b;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = (char *)s1;
	b = (char *)s2;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	tmp = dst;
	while (*a)
		*tmp++ = *a++;
	while (*b)
		*tmp++ = *b++;
	*tmp = '\0';
	return (dst);
}
