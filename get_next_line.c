/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:11:14 by svan-hoo          #+#    #+#             */
/*   Updated: 2024/01/08 18:19:39 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "writing.h"

char	*ft_strdup_gnl(const char *buffer)
{
	int		i;
	char	*temptr;

	i = ft_strchr_gnl(buffer, '\n');
	if (i == 0)
	{
		i = ft_strlen_gnl(buffer);
	}
	temptr = (char *)malloc((i + 1) * sizeof(char));
	if (temptr == NULL)
		return (NULL);
	temptr[i] = '\0';
	while (i--)
	{
		temptr[i] = buffer[i];
	}
	return (temptr);
}

char	*ft_strjoin_gnl(char **newline, const char *buffer)
{
	char		*temptr;
	const int	n_len = ft_strlen_gnl(*newline);
	const int	b_len = ft_strlen_gnl(buffer);
	const int	b_nl = ft_strchr_gnl(buffer, '\n');
	int			i;

	if (b_nl == 0)
		i = n_len + b_len;
	else
		i = n_len + b_nl;
	temptr = (char *)malloc((i + 1) * sizeof(char));
	if (temptr == NULL)
		return (ft_free_gnl(newline));
	temptr[i] = '\0';
	while (i-- > n_len)
	{
		temptr[i] = buffer[i - n_len];
	}
	i += 1;
	while (i--)
	{
		temptr[i] = (*newline)[i];
	}
	ft_free_gnl(newline);
	return (temptr);
}

char	*ft_read_gnl(char **newline, char *buffer, int fd)
{
	int		bytes_read;

	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && !ft_strchr_gnl(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free_gnl(newline));
		buffer[bytes_read] = '\0';
		*newline = ft_strjoin_gnl(newline, buffer);
		if (*newline == NULL)
			return (NULL);
	}
	return (*newline);
}

void	ft_remainder_gnl(char *buffer)
{
	const char	*remainder = buffer + ft_strchr_gnl(buffer, '\n');
	int			i;

	i = 0;
	if (remainder > buffer)
	{
		while (remainder[i])
		{
			buffer[i] = remainder[i];
			i++;
		}
	}
	while (i < BUFFER_SIZE)
	{
		buffer[i++] = '\0';
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*newline;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);
	}
	newline = ft_strdup_gnl(buffer);
	if (newline == NULL)
	{
		ft_memclear_gnl(buffer, BUFFER_SIZE + 1);
		return (NULL);
	}
	newline = ft_read_gnl(&newline, buffer, fd);
	if (newline == NULL)
	{
		ft_memclear_gnl(buffer, BUFFER_SIZE + 1);
		return (NULL);
	}
	ft_remainder_gnl(buffer);
	if (newline[0] == 0)
	{
		return (ft_free_gnl(&newline));
	}
	return (newline);
}

// int	main(void)
// {
// 	int			fd;
// 	int			line;
// 	char		*nextline;

// 	line = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	while (line < 15)
// 	{
// 		nextline = get_next_line(fd);
// 		printf("\n[%d]:\t%s", line, nextline);
// 		line++;
// 		if (nextline == NULL)
// 			break ;
// 		free(nextline);
// 	}
// 	close(fd);
// 	return (0);
// }

// int	main(void)
// {
// 	int			fd;
// 	int			line;
// 	char		*nextline;
// 	char		*output_conversion;

// 	line = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	while (line < 15)
// 	{
// 		nextline = get_next_line(fd);
// 		output_conversion = ft_writing(nextline, -1);
// 		if (output_conversion == NULL)
// 			return (1);
// 		printf("[%d]:\t%s\n", line, output_conversion);
// 		if (output_conversion)
// 			free(output_conversion);
// 		line++;
// 		if (nextline)
// 			free(nextline);
// 		else
// 			break ;
// 	}
// 	close(fd);
// 	return (0);
// }
int	main(void)
{
	int		line;
	char	*output_conversion;

	line = 0;
	while (line < 10)
	{
		output_conversion = ft_writing_cp("help", -1);
		fflush(stdout);
		if (output_conversion == NULL)
			return (1);
		printf("%s\n", output_conversion);
		free(output_conversion);
		line++;
		if (output_conversion == NULL)
			break ;
	}
	return (0);
}
