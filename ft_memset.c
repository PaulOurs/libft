/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 02:33:07 by paubello          #+#    #+#             */
/*   Updated: 2024/11/05 01:07:57 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (!s)
		return (NULL);
	if (!n)
		return (s);
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
		p[i++] = (unsigned char)c;
	return (s);
}
