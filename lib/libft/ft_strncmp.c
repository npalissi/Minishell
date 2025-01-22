/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:15:30 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/08 18:56:29 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && n && *s1)
	{
		s2++;
		s1++;
		n--;
	}
	if (!n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
