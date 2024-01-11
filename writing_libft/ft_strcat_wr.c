/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_wr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:45:15 by simon             #+#    #+#             */
/*   Updated: 2024/01/08 16:24:11 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writing_libft.h"

int	ft_strcat_wr(char *dest, const char *src)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (dest[i])
		i++;
	while (src[k])
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (k);
}
