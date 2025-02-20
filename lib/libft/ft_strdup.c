/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:42:11 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/19 19:06:29 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*save_start;
	char	*dup;

	dup = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dup)
		return (0);
	save_start = dup;
	while (*s)
		*dup++ = *(char *)s++;
	*dup = '\0';
	return (save_start);
}

char	*ft_strndup(char *s, int size, int is_free)
{
	char	*save_start;
	char	*save_s;
	char	*dup;

	dup = malloc(sizeof(char) * size + 1);
	if (!dup)
		return (0);
	save_start = dup;
	save_s = s;
	while (*s && size--)
		*dup++ = *(char *)s++;
	*dup = '\0';
	if (is_free)
		free(save_s);
	return (save_start);
}
