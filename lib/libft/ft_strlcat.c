/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:03:41 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/17 14:37:36 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	save_len;

	if (size <= 0)
		return (size + ft_strlen(src));
	save_len = ft_strlen(dst) + ft_strlen(src);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	ft_strlcpy(dst + ft_strlen(dst), src, size - ft_strlen(dst));
	return (save_len);
}
