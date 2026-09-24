/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbecer <marbecer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:28:19 by marbecer          #+#    #+#             */
/*   Updated: 2026/09/21 19:44:07 by marbecer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
return (i);
}
char	*ft_strdup(char *src)
{
	int		i;
	char	*new;
	size_t	len;

	len = ft_strlen(src) + 1;
	new = malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return (str);
	return (NULL);
}
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*v_dest;
	const unsigned char	*v_src;
	size_t				i;

	if (!dest && !src)
		return (0);
	v_dest = (unsigned char *)dest;
	v_src = (const unsigned char *)src;
	if (dest > src)
	{
		while (n--)
			v_dest[n] = v_src[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			v_dest[i] = v_src[i];
			i++;
		}
	}
	return (dest);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*v_dest;
	const unsigned char	*v_src;
	size_t				i;

	if (!dest && !src)
		return (0);
	v_dest = (unsigned char *)dest;
	v_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		v_dest[i] = v_src[i];
		i++;
	}
	return (dest);
}
