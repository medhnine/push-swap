#include "header.h"

int	count_words(char *str)
{
	int i, (count);
	i = 0;
	while (is_separtor(str[i]) == 1)
		i++;
	count = 0;
	while (str[i])
	{
		if ((is_separtor(str[i]) == 1 && is_separtor(str[i + 1]) == 0) || str[i
			+ 1] == '\0')
			count++;
		i++;
	}
	return (count);
}