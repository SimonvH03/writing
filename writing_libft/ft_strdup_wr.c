/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_wr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:39:42 by svan-hoo          #+#    #+#             */
/*   Updated: 2024/01/08 16:37:35 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writing_libft.h"

char	*ft_strdup_wr(const char *s)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (s[i])
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
