/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:46:44 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/08 18:22:20 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*clone;

	if (!dest && !src)
		return (dest);
	clone = dest;
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (clone);
}
