/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 05:58:59 by paubello          #+#    #+#             */
/*   Updated: 2024/11/13 02:52:27 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fill a block of memory with zeros.
 *
 * @param s Pointer to the start of the block of memory to fill.
 * @param n The number of bytes to fill.
 *
 * @details This function fills the first n bytes of the block of memory
 *          starting at the location pointed to by s with zeros.
 */

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
