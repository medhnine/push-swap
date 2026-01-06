#include "header.h"

// static void	print_linked(s_slot *began)
// {
// 	while (began)
// 	{
// 		printf("%d\n", began->value);
// 		began = began->next;
// 	}
// }

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
	int		index;

	track = *head;
	while (track)
	{
		check = *head;
		index = 0;
		while (check)
		{
			if (track->value > check->value)
				index++;
			check = check->next;
		}
		track->index = index;
		track = track->next;
	}
}

void	sort_three(s_slot **a_addr)
{
	s_slot	*track;
	int first, (second),(third);
	track = (*a_addr);
	first = track->value;
	second = track->next->value;
	third = track->next->next->value;
	if (first < second && second > third && third < first)
		move_to_exucte("rra", a_addr, NULL, 0);
	else if (first < second && second > third && third > first)
	{
		move_to_exucte("rra", a_addr, NULL, 0);
		move_to_exucte("sa", a_addr, NULL, 0);
	}
	else if (first > second && second < third && third > first)
		move_to_exucte("sa", a_addr, NULL, 0);
	else if (first > second && second > third)
	{
		move_to_exucte("sa", a_addr, NULL, 0);
		move_to_exucte("rra", a_addr, NULL, 0);
	}
	else if (first > second && second < third)
	{
		move_to_exucte("rra", a_addr, NULL, 0);
		move_to_exucte("rra", a_addr, NULL, 0);
	}
}

int	find_current_max(s_slot *b_addr, int max)
{
	int	pos;

	pos = 0;
	while (b_addr)
	{
		if (b_addr->index == max)
		{
			return (pos);
		}
		pos++;
		b_addr = b_addr->next;
	}
	return (0);
}

void	sort_stack_a(s_slot **a_addr, s_slot **b_addr, int max)
{
	int pos, (cost), (size);
	while ((*b_addr))
	{
		pos = find_current_max((*b_addr), max);
		size = size_of_stack((*b_addr));
		cost = size / 2;
		if ((*b_addr)->index == max)
		{
			move_to_exucte("pa", a_addr, b_addr, 0);
			max--;
		}
		else if (pos <= cost)
		{
			move_to_exucte("rb", a_addr, b_addr, 0);
		}
		else
			move_to_exucte("rrb", a_addr, b_addr, 0);
	}
}

void	sort_others(s_slot **a_addr, s_slot **b_addr, int chunk_size)
{
	int	min;

	min = 0;
	while ((*a_addr))
	{
		if ((*a_addr)->index <= min)
		{
			move_to_exucte("pb", a_addr, b_addr, 0);
			move_to_exucte("rb", a_addr, b_addr, 0);
			min++;
		}
		else if (((*a_addr)->index <= min + chunk_size))
		{
			move_to_exucte("pb", a_addr, b_addr, 0);
			min++;
		}
		else
			move_to_exucte("ra", a_addr, b_addr, 0);
	}
}

void	parssing_input(int ac, char **av, s_slot **a_addr)
{
	int	size;

	if (ac == 1 || av[1][0] == '\0' || check_validty(av) == 0)
	{
		printf("Error\n");
		exit(1);
	}
	make_structure(a_addr, av);
	size = size_of_stack((*a_addr));
	if (size <= 1 || is_sorted((*a_addr)) == 0)
		exit(1);
	if (check_duplicated_number((*a_addr)) == 1)
	{
		clean_up_node(a_addr);
		printf("Error\n");
		exit(1);
	}
	if (is_sorted((*a_addr)) == 0)
		exit(1);
	if (size == 3)
	{
		sort_three(a_addr);
		clean_up_node(a_addr);
		exit(1);
	}
	indexing_nodes(a_addr);
}

int	main(int ac, char **av)
{
	int	size;

	s_slot *head, (*b_addr);
	int chunk_size, (max);
	chunk_size = 1;
	head = NULL;
	b_addr = NULL;
	parssing_input(ac, av, &head);
	size = size_of_stack(head);
	head->largest = size - 1;
	max = head->largest;
	if (size <= 100 && size > 5)
		chunk_size = 15;
	else if (size <= 500 && size > 100)
		chunk_size = 30;
	sort_others(&head, &b_addr, chunk_size);
	sort_stack_a(&head, &b_addr, max);
	clean_up_node(&head);
	return (0);
}

//

// #include "push_swap.h"

// int get_chunk_size(int size)
// {
//     if (size >= 500)
//         return (30);
//     return (15);
// }

// void set_position(t_stack *stack)
// {
//     int i;

//     i = 0;
//     while (stack)
//     {
//         stack->pos = i;
//         stack = stack->next;
//         i++;
//     }
// }

// int find_pos_in_range(t_stack *a, int start, int end)
// {
//     int pos;

//     pos = 0;
//     while (a)
//     {
//         if (a->index >= start && a->index < end)
//             return (pos);
//         a = a->next;
//         pos++;
//     }
//     return (-1);
// }

// // Push From A → B by Chunks
// void push_chunks(t_stack **a, t_stack **b, int size)
// {
//     int chunk;
//     int i;

//     chunk = get_chunk_size(size);
//     i = 0;

//     while (*a)
//     {
//         if ((*a)->index <= i)
//         {
//             ft_pb(a, b);
//             ft_rb(b);
//             i++;
//         }
//         else if ((*a)->index <= i + chunk)
//         {
//             ft_pb(a, b);
//             i++;
//         }
//         else
//             ft_ra(a);
//     }
// }

// // Push Back B → A (Sort Phase)
// t_stack *find_max(t_stack *b)
// {
//     t_stack *max;

//     max = b;
//     while (b)
//     {
//         if (b->index > max->index)
//             max = b;
//         b = b->next;
//     }
//     return (max);
// }

// void push_back(t_stack **a, t_stack **b)
// {
//     t_stack *max;
//     int size;

//     while (*b)
//     {
//         size = ft_lstsize(*b);
//         set_position(*b);
//         max = find_max(*b);

//         if (max->pos <= size / 2)
//         {
//             while ((*b)->index != max->index)
//                 ft_rb(b);
//         }
//         else
//         {
//             while ((*b)->index != max->index)
//                 ft_rrb(b);
//         }
//         ft_pa(a, b);
//     }
// }

// void ft_chunk_algo(t_stack **a, t_stack **b)
// {
//     int size;
//     size = ft_lstsize(*a);
//     ft_chunk_index(a);

//     push_chunks(a,b,size);
//     push_back(a,b);
// }