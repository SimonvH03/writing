/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_libft.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:30:54 by simon             #+#    #+#             */
/*   Updated: 2024/01/08 16:38:50 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITING_LIBFT_H
# define WRITING_LIBFT_H
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

void	ft_bzero_wr(void *s, size_t n);
int		ft_isprint_wr(char c);
int		ft_charcat_wr(char *dest, const char c);
int		ft_strcat_wr(char *dest, const char *src);
char	*ft_strdup_wr(const char *s);
int		ft_strlen_wr(const char *str);

#endif