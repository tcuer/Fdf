/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 14:55:52 by tcuer             #+#    #+#             */
/*   Updated: 2015/05/04 11:28:12 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ret;
	int		tmp;
	size_t	size;
	char	minus;

	minus = (n < 0) ? -1 : 1;
	size = 1 + (n < 0);
	tmp = n;
	while ((n = n / 10))
		size++;
	n = tmp;
	if ((ret = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	ret[size--] = '\0';
	ret[size--] = minus * (n % 10) + '0';
	while ((n = n / 10))
		ret[size--] = minus * (n % 10) + '0';
	if (minus < 0)
		ret[size] = '-';
	return (ret);
}
