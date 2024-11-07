/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:33:40 by paubello          #+#    #+#             */
/*   Updated: 2024/11/07 18:44:32 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	// if (little_len > len)
	// 	return (NULL);
	i = 0;
	while (big[i] && i < len - little_len + 1)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && i + j < len)
			j++;
		if (j == little_len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
