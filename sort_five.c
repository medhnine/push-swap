#include "header.h"

int	find_position(s_slot *a_addr, int target)
{
	int	pos;

	pos = 1;
	while (a_addr->index != target)
	{
		a_addr = a_addr->next;
		pos++;
	}
	return (pos);
}

void	push_node(s_slot **a_addr, s_slot **b_addr)
{
	int	target;
	int	pos;

	target = 0;
	pos = 0;
	while (target <= 1)
	{
		pos = find_position(*a_addr, target);
		if ((*a_addr)->index == target)
		{
			move_to_exucte("pb", a_addr, b_addr, 0);
			target++;
		}
		else if (pos <= 2)
			move_to_exucte("ra", a_addr, b_addr, 0);
		else
			move_to_exucte("rra", a_addr, b_addr, 0);
	}
}

void	sort_five(s_slot **a_addr, s_slot **b_addr)
{
	push_node(a_addr, b_addr);
	sort_three(a_addr);
	move_to_exucte("pa", a_addr, b_addr, 0);
	move_to_exucte("pa", a_addr, b_addr, 0);
}

void	sort_four(s_slot **a_addr, s_slot **b_addr)
{
	int	check;

	check = 0;
	while (check == 0)
	{
		if ((*a_addr)->index == 0)
		{
			move_to_exucte("pb", a_addr, b_addr, 0);
			check++;
		}
		else
			move_to_exucte("ra", a_addr, b_addr, 0);
	}
	sort_three(a_addr);
	move_to_exucte("pa", a_addr, b_addr, 0);
}

void	sort_under_five(s_slot **a_addr, s_slot **b_addr, int size)
{
	if (size == 2)
		move_to_exucte("sa", a_addr, b_addr, 0);
	else if (size == 3)
		sort_three(a_addr);
	else if (size == 4)
		sort_four(a_addr, b_addr);
	else if (size == 5)
		sort_five(a_addr, b_addr);
	clean_up_node(a_addr);
	exit(1);
}
