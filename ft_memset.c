/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 02:33:07 by paubello          #+#    #+#             */
/*   Updated: 2024/11/13 02:52:00 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Sets the first n bytes of the memory
 *			area pointed to by s with the constant byte c.
 *
 * @param s Pointer to the memory area to be filled.
 * @param c The byte value to be set.
 * @param n The number of bytes to be set to the value.
 *
 * @return The original pointer s.
 */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
		p[i++] = (unsigned char)c;
	return (s);
}
