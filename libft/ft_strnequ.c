/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:56:34 by tcuer             #+#    #+#             */
/*   Updated: 2014/11/13 10:08:45 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 == *s2 && *s1 && *s2 && i < n)
	{
		i++;
		if (i == n)
		{
			if (*s1 - *s2 == 0)
				return (1);
			return (0);
		}
		s1++;
		s2++;
	}
	if ((*s1 - *s2) == 0)
		return (1);
	return (0);
}
