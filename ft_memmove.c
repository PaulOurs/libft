/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 06:39:53 by paubello          #+#    #+#             */
/*   Updated: 2024/09/16 06:39:53 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
		ft_memcpy((char *)dest + n, (char *)src + n, n);
	return (dest);
}

int main() {
    char src[10] = "Hello!";
    char dest[10] = "XXXXXXXX";

    // Test case: Copying from src to dest with overlap
    printf("Testing ft_memmove with overlap: ");
    ft_memmove(dest, src, strlen(src));
    if (strcmp(dest, src) == 0) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }

    // Test case: Copying from src to dest without overlap
    printf("Testing ft_memmove without overlap: ");
    ft_memmove(dest, src, strlen(src));
    if (strcmp(dest, src) == 0) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }

    // Test case: Copying from src to dest with src and dest being the same
    printf("Testing ft_memmove with src and dest being the same: ");
    ft_memmove(dest, dest, strlen(dest));
    if (strcmp(dest, "XXXXXXXX") == 0) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }

    // Test case: Copying from src to dest with n being 0
    printf("Testing ft_memmove with n being 0: ");
    ft_memmove(dest, src, 0);
    if (strcmp(dest, "XXXXXXXX") == 0) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }

    return 0;
}
