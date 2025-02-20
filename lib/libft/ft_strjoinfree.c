/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:44:00 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/19 19:08:03 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char const *s2, int is_free)
{
	char	*str;
	char	*save_str;
	char	*save_s1;

	if (!s1)
		return (NULL);
	str = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	save_str = str;
	save_s1 = s1;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	if (is_free)
		free(save_s1);
	return (save_str);
}
