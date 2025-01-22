/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:48:08 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/15 21:24:19 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*s;

	if ((nmemb * size > 4294967295) || ((int)size < 0 && (int)nmemb < 0))
		return (NULL);
	s = malloc(size * nmemb);
	if (!s)
		return (NULL);
	ft_memset(s, 0, nmemb * size);
	return (s);
}
