/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:41:51 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/12 14:27:29 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char *str, char c)
{
	char	*s;
	char	*s_clone;
	char	*str_clone;

	if (!str || !c)
		return (NULL);
	s = dh_malloc(ft_strlen(str) + 2);
	if (!s)
		return (NULL);
	s_clone = s;
	str_clone = str ;
	while (str && *str)
		*s++ = *str ++;
	*s++ = c;
	*s = '\0';
	dh_free(str_clone);
	return (s_clone);
}
