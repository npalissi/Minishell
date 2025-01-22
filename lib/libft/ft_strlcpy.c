/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:40:00 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/09 12:24:56 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = (ft_strlen(src));
	while (size && (size - 1) > 0 && *src)
	{
		*dst++ = *src++;
		size--;
	}
	if (size)
		*dst = '\0';
	return (src_len);
}
