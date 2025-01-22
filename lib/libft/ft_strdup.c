/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:42:11 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/10 18:13:55 by edubois-         ###   ########.fr       */
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
