/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:59:12 by svan-hoo          #+#    #+#             */
/*   Updated: 2024/01/08 16:21:08 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen_wr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}