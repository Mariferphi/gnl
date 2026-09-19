/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbecer <marbecer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:27:46 by marbecer          #+#    #+#             */
/*   Updated: 2026/09/19 18:55:37 by marbecer         ###   ########.fr       */
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
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes != 0 && ft_strchr(saved_buff, NEW_LINE) != NEW_LINE)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(saved_buff);
			return (NULL);
		}
		saved_buff[bytes] = '\0';
		temp = saved_buff;
		free(saved_buff);
		saved_buff = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (saved_buff);
}
// conseguir linea (valor retorno), y guardar el resto,
//(pasandolo con puntero pq solo retorna line)
static char	*line_rest(char **saved_buff)
{
	char	*line;
	char	*save_rest;
	int		i;

	i = 0;
	while(ft_strchr(&saved_buff, NEW_LINE) != NEW_LINE)
		i++;
	
	*saved_buff = save_rest;
	return(line);
}

char	*get_next_line(int fd) // newline? si -> return(line), sno ->
{
	static char *saved_buff;
	char *line;
}

// 1º Existe el archivo? el FD es válido,
// 2º comprobamos si hay algo guardado
// 3º lee y guarda el blque leido en la estatica read and save
//4 comprobar si hay NEW_LINE, si hay devuelve linea y guarda el resto,