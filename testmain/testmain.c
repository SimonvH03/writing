/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:50:29 by svan-hoo          #+#    #+#             */
/*   Updated: 2024/01/08 17:03:59 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

char	*ft_writing(const char *str, int n);

int	main(void)
{
	const char	*str1 = "line";
	char		*tmp;

	tmp = ft_writing(str1, -1);
	printf("\nft_writing:	%s\n\n", tmp);
	free(tmp);
	return (0);
}
