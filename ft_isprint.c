/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 04:55:13 by paubello          #+#    #+#             */
/*   Updated: 2024/11/13 02:53:09 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is a printable character.
 *
 * @param c The character to be checked.
 *
 * @return 1 if the character is a printable character, 0 otherwise.
 *
 * @note Printable characters are characters with ASCII values between 32 and 126
 */

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}
