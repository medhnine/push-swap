#include "header.h"

static void	print_linked(s_slot *began)
{
	while (began)
	{
		printf("%d\n", began->value);
		began = began->next;
	}
}

static void	add_back(s_slot **target, s_slot *node)
{
	s_slot	*track;

	if (!node)
		return ;
	if (!*target)
	{
		*target = node;
		return ;
	}
	track = *target;
	while (track->next)
		track = track->next;
	track->next = node;
}

static s_slot	*add_new(int value)
{
	s_slot	*new;

	new = malloc(sizeof(s_slot));
	new->value = value;
	new->next = NULL;
	return (new);
}

static int	check_validty(char **av)
{
	int i, (x);
	i = 1;
	while (av[i])
	{
		x = 0;
		while (av[i][x])
		{
			if (av[i][x] == '-' || av[i][x] == '+')
			{
				x++;
				if ((av[i][x] >= '0' && av[i][x] <= '9'))
					x++;
				else
					return (0);
			}
			else if ((av[i][x] >= '0' && av[i][x] <= '9')
				|| is_separtor(av[i][x]) == 1)
				x++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	check_duplicated_number(s_slot *head)
{
	s_slot	*track;
	s_slot	*check;

	track = head;
	while (track->next)
	{
		check = track;
		while (check->next)
		{
			check = check->next;
			if (check->value == track->value)
				return (1);
		}
		track = track->next;
	}
	return (0);
}

int	is_sorted(s_slot *a_addr)
{
	s_slot	*track;
	s_slot	*check;

	track = a_addr;
	while (track->next)
	{
		check = track;
		while (check->next)
		{
			check = check->next;
			if (track->value > check->value)
				return (1);
		}
		track = track->next;
	}
	return (0);
}

static void	clean_up_node(s_slot **node)
{
	s_slot	*tarck;
	s_slot	*temp;

	if (node == NULL)
		return ;
	tarck = *node;
	while (tarck)
	{
		temp = tarck;
		tarck = tarck->next;
		free(temp);
		temp = NULL;
	}
	*node = NULL;
	free(*node);
}

static void	clean_up_array(char **ptr)
{
	int	move;

	if (ptr == NULL)
		return ;
	move = 0;
	while (ptr[move])
	{
		free(ptr[move]);
		ptr[move] = NULL;
		move++;
	}
	free(ptr);
}

static int	size_of_stack(s_slot *start)
{
	int	count;

	count = 0;
	while (start)
	{
		count++;
		start = start->next;
	}
	return (count);
}

static int	ft_atoi(char *str, s_slot **head, char **ptr)
{
	int		sign;
	long	result;

	sign = 1;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
	{
		clean_up_node(head);
		clean_up_array(ptr);
		printf("Error\n");
		exit(1);
	}
	return ((int)result * sign);
}

void	make_structure(s_slot **head, char **av)
{
	s_slot	*track;
	char	**ptr;

	int move, (i), (value);
	*head = NULL;
	move = 1;
	while (av[move])
	{
		i = 0;
		ptr = ft_split(av[move]);
		if (ptr[i] == NULL)
		{
			if (move > 1)
			{
				clean_up_array(ptr);
				exit(1);
			}
			exit(1);
		}
		while (ptr[i])
		{
			value = ft_atoi(ptr[i], head, ptr);
			track = add_new(value);
			add_back(head, track);
			i++;
		}
		clean_up_array(ptr);
		move++;
	}
}

void	indexing_nodes(s_slot **head)
{
	s_slot	*track;
	s_slot	*check;
	int		index,max;

	track = *head;
	while (track->next)
	{
		check = *head;
		index = 0;
		while (check->next)
		{
			if (track->value > check->value)
				index++;
			check = check->next;
		}
		if (track->value > check->value)
			index++;
		track->index = index;
		track = track->next;
	}
	check = *head;
	printf("max : %d\n", index);
	index = 0;
	while (check->next)
	{
		if (track->value > check->value)
			index++;
		check = check->next;
	}
	track->index = index;
	printf("max : %d\n", index);
}

void	sort_three(s_slot **a_addr)
{
	s_slot	*track;

	track = (*a_addr);
	if (track->index < track->next->index
		&& track->next->index > track->next->next->index)
	{
		printf("if %d < %d, and %d > %d\n", track->index, track->next->index,
			track->next->index, track->next->next->index);
		move_to_exucte("rra", a_addr, NULL, 0);
		move_to_exucte("sa", a_addr, NULL, 0);
	}
	else if (track->index > track->next->index
		&& track->next->index < track->next->next->index)
	{
		move_to_exucte("ra", a_addr, NULL, 0);
	}
	else if (track->index > track->next->index
		&& track->next->index > track->next->next->index)
	{
		move_to_exucte("rra", a_addr, NULL, 0);
		move_to_exucte("sa", a_addr, NULL, 0);
	}
}

void	sort_stack_a(s_slot **a_addr, s_slot **b_addr, int max)
{
	while ((*b_addr))
	{
		if ((*b_addr)->index == max)
		{
		 	move_to_exucte("pa", a_addr, b_addr, 0);
			max--;
		}
		else
			move_to_exucte("rb", a_addr, b_addr, 0);
	}
}

void	sort_others(s_slot **a_addr, s_slot **b_addr, int chunk_size)
{
	int min, (max), (mid),(temp);
	min = 0;
	max = chunk_size - 1;
	mid = (min + max) / 2;
	while ((*a_addr))
	{
		mid = (min + max) / 2;
		if ((*a_addr)->index >= min && (*a_addr)->index <= max)
		{
			temp = (*a_addr)->index;
			move_to_exucte("pb", a_addr, b_addr, 0);
			if (min == temp)
				min++;
			max++;
			if (temp <= mid)
				move_to_exucte("rb", a_addr, b_addr, 0);
			mid = (min + max) / 2;
		}
		else
			move_to_exucte("ra", a_addr, b_addr, 0);
	}
}

void	push_swap(int ac, char **av)
{
	s_slot *head, (*b_addr);
	int chunk_size,(max);

	chunk_size = 1;
	head = NULL;
	b_addr = NULL;
	if (ac == 1 || av[1][0] == '\0' || check_validty(av) == 0)
	{
		printf("Error\n");
		exit(1);
	}
	make_structure(&head, av);
	if (size_of_stack(head) <= 1 || is_sorted(head) == 0)
		exit(1);
	if (check_duplicated_number(head) == 1)
	{
		clean_up_node(&head);
		printf("Error\n");
		exit(1);
	}
	if (is_sorted(head) == 0)
		exit(1);
	indexing_nodes(&head);
	head->largest = size_of_stack(head) - 1;
	max = head->largest;
	printf("largset %d\n", head->largest);
	if (size_of_stack(head) <= 100 && size_of_stack(head) > 5)
		chunk_size = 15;
	else if (size_of_stack(head) < 500 && size_of_stack(head) > 100)
		chunk_size = 25;
	sort_others(&head, &b_addr, chunk_size);
	print_linked(head);
	sort_stack_a(&head, &b_addr, max);
	clean_up_node(&head);
}