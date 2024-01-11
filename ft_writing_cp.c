/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing_cp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:57:06 by simon             #+#    #+#             */
/*   Updated: 2024/01/08 18:40:53 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writing.h"

int	ft_convert_writing(char *dest, const char c)
{
	const char	*bp_reference = "abtnvfr";
	char		backprint[2];
	char		octal[4];

	ft_bzero_wr(backprint, 2);
	ft_bzero_wr(octal, 4);
	ft_charcat_wr(dest, '\\');
	if (c == '\0')
		ft_charcat_wr(dest, '0');
	else if (ft_isbackprint_wr(c))
	{
		backprint[0] = bp_reference[c - '\a'];
		ft_strcat_wr(dest, backprint);
		return (1);
	}
	else if (c == '\177')
		ft_strcat_wr(octal, "DEL");
	else if (ft_isoctal_wr(c))
	{
		octal[0] = ((c >> 6) & 7) + '0';
		octal[1] = ((c >> 3) & 7) + '0';
		octal[2] = ((c >> 0) & 7) + '0';
	}
	ft_strcat_wr(dest, octal);
	return (1);
}

int	ft_mark_writing(char *dest, const char *str, int i)
{
	const int	strlen = ft_strlen_wr(str);

	if (str[i] == '\0')
		return (ft_strcat_wr(dest, MARKZERO));
	else if (!ft_isprint_wr(str[i]))
		return (ft_strcat_wr(dest, MARKSPEC));
	else if (i < strlen)
		return (ft_strcat_wr(dest, MARKDOWN));
	else
		return (ft_strcat_wr(dest, MARKOUT));
}

int	ft_construct_writing(char *dest, const char *str, int n)
{
	int			fellows;
	int			i;

	i = 0;
	while (i < n)
	{
		ft_mark_writing(dest, str, i);
		fellows = ft_lookahead_wr(&str[i], n - i);
		while (fellows--)
		{
			if (!ft_isprint_wr(str[i]))
				ft_convert_writing(dest, str[i]);
			else
				ft_charcat_wr(dest, str[i]);
			i++;
		}
	}
	ft_strcat_wr(dest, MARKDOWN);
	return (i);
}

char	*ft_writing_cp(const char *str, int n)
{
	char	*outstr;
	int		strlen;
	int		size;

	if (str == NULL)
		return (ft_strdup_wr("(null)"));
	strlen = ft_strlen_wr(str);
	if (n == 0)
		n = strlen;
	else if (n == -1)
		n = strlen + 1;
	size = ft_size_converted(str, n) + ft_strlen_wr(MARKDOWN);
	if (n > strlen + 1)
		size += ft_strlen_wr(MARKOUT);
	outstr = (char *)malloc((size + 1) * sizeof(char));
	if (outstr == NULL)
		return (NULL);
	outstr[size] = '\0';
	printf("\n\n%d\n\n", size);
	ft_construct_writing(outstr, str, n);
	return (outstr);
}

// int	main(void)
// {
// 	char		*tmp;

// 	tmp = ft_writing("lin", -1);
// 	if (tmp == NULL)
// 		return (1);
// 	printf("\nft_writing:\t%s\n\n", tmp);
// 	free(tmp);
// 	return (0);
// }

// int	main(void)
// {
// 	int		line;
// 	char	*output_conversion;

// 	line = 0;
// 	while (line < 1)
// 	{
// 		output_conversion = ft_writing_cp("help", -1);
// 		if (output_conversion == NULL)
// 			return (1);
// 		printf("%s\n", output_conversion);
// 		free(output_conversion);
// 		line++;
// 		if (output_conversion == NULL)
// 			break ;
// 	}
// 	return (0);
// }
