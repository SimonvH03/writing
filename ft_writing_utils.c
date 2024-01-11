/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:57:06 by simon             #+#    #+#             */
/*   Updated: 2024/01/08 18:40:05 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writing.h"

int	ft_isbackprint_wr(char c)
{
	return (c >= '\a' && c <= '\r');
}

int	ft_isoctal_wr(char c)
{
	return (!ft_isprint_wr(c) && !ft_isbackprint_wr(c));
}

int	ft_lookahead_wr(const char *str, int n)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		while (n-- && str[i] == '\0')
			i++;
	else if (ft_isprint_wr(str[i]))
		while (n-- && ft_isprint_wr(str[i]))
			i++;
	else if (ft_isbackprint_wr(str[i]))
		while (n-- && ft_isbackprint_wr(str[i]))
			i++;
	else if (ft_isoctal_wr(str[i]))
		while (n-- && ft_isoctal_wr(str[i]))
			i++;
	return (i);
}

int	ft_size_converted(const char *str, int n)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (i < n)
	{
		if (str[i] == '\0')
		{
			size += ft_strlen_wr(MARKZERO);
			size += ft_lookahead_wr(&str[i], n - i) * 2;
		}
		else if (ft_isbackprint_wr(str[i]))
		{
			size += ft_strlen_wr(MARKSPEC);
			size += ft_lookahead_wr(&str[i], n - i) * 2;
		}
		else if (ft_isoctal_wr(str[i]))
		{
			size += ft_strlen_wr(MARKSPEC);
			size += ft_lookahead_wr(&str[i], n - i) * 4;
		}
		else
		{
			size += ft_strlen_wr(MARKDOWN);
			size += ft_lookahead_wr(&str[i], n - i);
		}
		i += ft_lookahead_wr(&str[i], n - i);
	}
	return (size);
}
