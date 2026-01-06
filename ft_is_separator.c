#include "header.h"

int	is_separtor(char c)
{
	if ((c >= 8 && c <= 13) || c == 32)
		return (1);
	return (0);
}