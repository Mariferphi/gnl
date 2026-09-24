#include "get_next_line.h"
#include <stdio.h>
int main()
{
	char	*nl_ptr;
	char *line;
	char	str[] = "holao gato\nmiau miuau"; 
	int	len;
	if (ft_strchr(str, '\n'))
	{
		nl_ptr = ft_strchr(str, '\n');
		len = ft_strlen(nl_ptr);
		printf("sincambiar%s\n", str);
		ft_memmove(line, str, len);
		str[len] = '\0';
		printf("line%s\n", str);
		ft_memmove(str, nl_ptr, len);
		printf("resto%s\n", str);
	}
	return (0);
}