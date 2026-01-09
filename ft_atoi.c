#include "header.h"

static int	check_range(long number)
{
	if ((number > 2147483647 || number < -2147483648))
		return (1);
	return (0);
}

int	ft_atoi(char *str, s_slot **head, char **ptr)
{
	long	result;

	int sign, (count);
	sign = 1;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	result = 0;
	count = 0;
	while (str[count] >= '0' && str[count] <= '9')
	{
		result = result * 10 + (str[count++] - '0');
		if (count > 10 || check_range((result * sign)) == 1)
		{
			clean_up_node(head);
			clean_up_array(ptr);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	return ((int)result * sign);
}
