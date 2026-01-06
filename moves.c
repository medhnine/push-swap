#include "header.h"
#include <unistd.h>

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

static void	swap_stack_a(s_slot **a_addr, int check)
{
	s_slot	*temp;

	if (!(*a_addr) || !(*a_addr)->next)
		return ;
	temp = (*a_addr)->next;
	(*a_addr)->next = temp->next;
	temp->next = (*a_addr);
	(*a_addr) = temp;
	if (check == 0)
		write(1, "sa\n", 3);
}

static void	swap_stack_b(s_slot **b_addr, int check)
{
	s_slot	*temp;

	if (size_of_stack(*b_addr) == 1)
		return ;
	temp = (*b_addr)->next;
	(*b_addr)->next = temp->next;
	temp->next = (*b_addr);
	(*b_addr) = temp;
	if (check == 0)
		write(1, "sb\n", 3);
}

void	swap_stack_a_and_b(s_slot **a_addr, s_slot **b_addr)
{
	if (size_of_stack(*a_addr) == 1 && size_of_stack(*b_addr) == 1)
		return ;
	swap_stack_a(a_addr, 1);
	swap_stack_b(b_addr, 1);
	write(1, "ss\n", 3);
}

void	push_top_of_a(s_slot **a_addr, s_slot **b_addr, int check)
{
	s_slot	*track;

	if (!(*a_addr))
		return ;
	track = (*a_addr);
	(*a_addr) = (*a_addr)->next;
	track->next = (*b_addr);
	(*b_addr) = track;
	if (check == 0)
		write(1, "pb\n", 3);
}

void	push_top_of_b(s_slot **a_addr, s_slot **b_addr, int check)
{
	s_slot	*track;

	if (!(*b_addr))
		return ;
	track = (*b_addr);
	(*b_addr) = (*b_addr)->next;
	track->next = (*a_addr);
	(*a_addr) = track;
	if (check == 0)
		write(1, "pa\n", 3);
}

void	rotate_stack_a(s_slot **a_addr, int check)
{
	s_slot	*track;
	s_slot	*temp;

	if (size_of_stack(*a_addr) <= 1)
		return ;
	temp = (*a_addr);
	track = (*a_addr);
	while (track->next)
		track = track->next;
	track->next = (*a_addr);
	(*a_addr) = (*a_addr)->next;
	temp->next = NULL;
	if (check == 0)
		write(1, "ra\n", 3);
}

void	rotate_stack_b(s_slot **b_addr, int check)
{
	s_slot	*track;
	s_slot	*temp;

	if (size_of_stack(*b_addr) <= 1)
		return ;
	temp = (*b_addr);
	track = (*b_addr);
	while (track->next)
		track = track->next;
	track->next = (*b_addr);
	(*b_addr) = (*b_addr)->next;
	temp->next = NULL;
	if (check == 0)
		write(1, "rb\n", 3);
}

void	rotate_stack_a_and_b(s_slot **a_addr, s_slot **b_addr)
{
	rotate_stack_a(a_addr, 1);
	rotate_stack_b(b_addr, 1);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(s_slot **a_addr, int check)
{
	s_slot *prev, (*last);
	if (size_of_stack(*a_addr) < 2)
		return ;
	prev = NULL;
	last = (*a_addr);
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = (*a_addr);
	(*a_addr) = last;
	if (check == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(s_slot **b_addr, int check)
{
	s_slot *prev, (*last);
	if (size_of_stack((*b_addr)) < 2)
		return ;
	prev = NULL;
	last = (*b_addr);
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = (*b_addr);
	(*b_addr) = last;
	if (check == 0)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_a_and_b(s_slot **a_addr, s_slot **b_addr)
{
	reverse_rotate_a(a_addr, 1);
	reverse_rotate_b(b_addr, 1);
	write(1, "rrr\n", 4);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	move_to_exucte(char *move_name, s_slot **a_addr, s_slot **b_addr,
		int check)
{
	if (ft_strcmp(move_name, "sa") == 0)
		swap_stack_a(a_addr, check);
	else if (ft_strcmp(move_name, "sb") == 0)
		swap_stack_b(b_addr, check);
	else if (ft_strcmp(move_name, "pb") == 0)
		push_top_of_a(a_addr, b_addr, check);
	else if (ft_strcmp(move_name, "pa") == 0)
		push_top_of_b(a_addr, b_addr, check);
	else if (ft_strcmp(move_name, "ra") == 0)
		rotate_stack_a(a_addr, check);
	else if (ft_strcmp(move_name, "rb") == 0)
		rotate_stack_b(b_addr, check);
	else if (ft_strcmp(move_name, "rr") == 0)
		rotate_stack_a_and_b(a_addr, b_addr);
	else if (ft_strcmp(move_name, "rra") == 0)
		reverse_rotate_a(a_addr, check);
	else if (ft_strcmp(move_name, "rrb") == 0)
		reverse_rotate_b(b_addr, check);
	else if (ft_strcmp(move_name, "rrr") == 0)
		reverse_rotate_a_and_b(a_addr, b_addr);
}