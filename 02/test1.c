#include "get_next_line.h"
#include <stdio.h>
int main()
{
	char	*nl_ptr;
	char	str[] = "holao gato miau miuau"; 
	int	len;

	nl_ptr = ft_strchr(str, '\n');
	len = ft_strlen(nl_ptr);
	printf("%s\n", str);
	ft_memmove(str, nl_ptr, len);
	str[len] = '\0';
	printf("%s", str);
	return (0);
}