/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:43:59 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/08 17:43:30 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_seen;

	last_seen = NULL;
	while (*s)
	{
		if (*s++ == (unsigned char)c)
			last_seen = s - 1;
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return ((char *)last_seen);
}
