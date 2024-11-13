/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 04:50:50 by paubello          #+#    #+#             */
/*   Updated: 2024/11/13 02:52:45 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is an ASCII character.
 *
 * @param c The character to be checked.
 *
 * @return 1 if the character is an ASCII character, 0 otherwise.
 */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
