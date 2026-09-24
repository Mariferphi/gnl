/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbecer <marbecer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:27:46 by marbecer          #+#    #+#             */
/*   Updated: 2026/09/21 19:58:01 by marbecer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read and save buffer, malloc a buffer de read,
//mientras no strchr newline en savedbuffer hacer read,
// si bytes == -1 entonces liberar buffers, return null,
static char	*read_save(int fd, char *saved_buff)
{
	int		bytes;
	char	*buffer;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !(ft_strchr(buffer, NEW_LINE)))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		temp = ft_strjoin(saved_buff, buffer);
		free(saved_buff);
		saved_buff = temp;
	}
	free(buffer);
	return (saved_buff);
}

static char	*get_line(char *saved_buff)
{
	char	*line;
	size_t		len;

	len = 0;
	while (saved_buff[len] && saved_buff[len] != NEW_LINE)
		len++;
	if (saved_buff[len] == 0)
		line = malloc(len + 1);
	else
	{
		len++;
		line = malloc(len + 1);
	}
	if(!line)
		return (NULL);
	line[len] = '\0';
	ft_memmove(line, saved_buff, len);
	return (line);
}	


static char	*save_rest(char *saved_buff)
{
	char	*nl_ptr;
	int	len; 
	
	nl_ptr = ft_strchr(saved_buff, NEW_LINE);
	len = (ft_strlen(saved_buff) - ft_strlen(nl_ptr));
	if (nl_ptr)
	{
		ft_memmove(saved_buff, nl_ptr + 1, len);
		saved_buff[len] = '\0';
		return (saved_buff);
	}
	free (saved_buff);
	return (NULL);
}

char	*get_next_line(int fd) // newline? si -> return(line), sno ->
{
	static char *saved_buff = NULL;
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!saved_buff)
		return (NULL);
	saved_buff = read_save(fd, saved_buff);
	if(saved_buff == NULL)
	{
		free(saved_buff);
		return (NULL);
	}
	line = get_line(saved_buff);
	save_rest(saved_buff);
	return (line);
}

// 1º Existe el archivo? el FD es válido,
// 2º comprobamos si hay algo guardado
// 3º lee y guarda el blque leido en la estatica read and save
//4 comprobar si hay NEW_LINE, si hay devuelve linea y guarda el resto,
