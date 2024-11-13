/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 05:09:32 by paubello          #+#    #+#             */
/*   Updated: 2024/11/13 02:52:48 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is a digit.
 *
 * @param c The character to be checked.
 *
 * @return 1 if the character is a digit, 0 otherwise.
 */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
