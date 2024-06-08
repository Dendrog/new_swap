/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:31:21 by jakim             #+#    #+#             */
/*   Updated: 2024/06/08 17:32:43 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < (a->size - 1))
	{
		if (a->stack[i] > a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted_b(t_stack *a)
{
	int	i;

	i = 0;
	while (i < (a->size - 1))
	{
		if (a->stack[i] < a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static t_stack	*stack_cpy(t_stack *a, int size)
{
	t_stack	*st;
	int	i;
	
	i = 0;
	st = (t_stack *)malloc(sizeof(t_stack));
	st->size = size;
	st->stack = (int *)malloc(sizeof(int) * (size + 5));
	null_guard(st->stack);
	while (i < size)
	{
		st->stack[i] = a->stack[i];
		i++;
	}
	return (st);
}

static void	search_pivot(t_stack *st, int size, int *p1, int *p2)
{
	int	i;
	int	k;
	int	tmp;
	t_stack *a;

	a = stack_cpy(st, size);
	i = 0;
	while (i < size - 1)
	{
		k = 0;
		while (k < size - 1 - i)
		{
			if (a->stack[k] > a->stack[k + 1])
			{
				tmp = a->stack[k];
				a->stack[k] = a->stack[k + 1];
				a->stack[k + 1] = tmp;
			}
			k++;
		}
		i++;
	}
	*p1 = a->stack[size / 3 - 1];
	*p2 = a->stack[size / 3 * 2 - 1];
	free(a->stack);
	free(a);
}

static void	mini_sort(t_stack *a, int size, t_output **out)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (a->stack[0] > a->stack[1])
			sa(a, out);
	}
	else if (size == 3)
	{
		if (size == a->size)
		{
			if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] > a->stack[2])
			{
				rra(a, out);
				sa(a, out);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
				sa(a, out);
			else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
				rra(a, out);
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2])
				ra(a, out);
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
			{
				ra(a, out);
				sa(a, out);
			}
		}
		else
		{
			if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] > a->stack[2])
			{
				ra(a, out);
				sa(a, out);
				rra(a, out);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
				sa(a, out);
			else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
			{
				ra(a, out);
				sa(a, out);
				rra(a, out);
				sa(a, out);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2])
			{
				sa(a, out);
				ra(a, out);
				sa(a, out);
				rra(a, out);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
			{
				sa(a, out);
				ra(a, out);
				sa(a, out);
				rra(a, out);
				sa(a, out);
			}
		}
	}
}

static void	mini_sort_b(t_stack *a, int size, t_output **out)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (a->stack[0] < a->stack[1])
			sb(a, out);
	}
	else if (size == 3)
	{
		if (size == a->size)
		{
			if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
			{
				rb(a, out);
				sb(a, out);
			}
			else if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] > a->stack[2])
			{
				rb(a, out);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
				rrb(a, out);
			else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
				sb(a, out);
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2])
			{
				rrb(a, out);
				sb(a, out);
			}
		}
		else
		{
			if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
			{
				sb(a, out);
				rb(a, out);
				sb(a, out);
				rrb(a, out);
				sb(a, out);
			}
			else if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] > a->stack[2])
			{
				sb(a, out);
                rb(a, out);
                sb(a, out);
                rrb(a, out);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
			{
				rb(a, out);
                sb(a, out);
                rrb(a, out);
                sb(a, out);
			}
			else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
			{
				sb(a, out);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2])
			{
				rb(a, out);
                sb(a, out);
                rrb(a, out);
			}
		}
	}
}

void	sort(t_stack *a, t_stack *b, int size, t_output **out)
{
	int	r;
	int	s;
	int	m;
	int	i;
	int p1;
	int p2;
	int	count;

	i = 0;
	r = 0;
	s = 0;
	m = 0;
	if (size <= 3)
	{
		mini_sort(a, size, out);
		return ;
	}
	search_pivot(a, size, &p1, &p2);
	count = 0;
	if (is_sorted(a))
		return ;
	while (i < size)
	{
		if (a->stack[0] <= p1)
		{
			while (count)
			{
				rb(b, out);
				count--;
			}
			pb(a, b, out);
			s++;
		}
		else if (a->stack[0] <= p2)
		{
			pb(a, b, out);
			count++;
			//rb(b);
			m++;
		}
		else
		{
			if (count)
			{
				rr(a, b, out);
				count--;
			}
			else
				ra(a, out);
			r++;
		}
		i++;
	}
	while (count)
	{
		rb(b, out);
		count--;
	}
	i = 0;
	if (a->size != r)
	{
		while (i < r)
		{
			if (i < m)
				rrr(a, b, out);
			else
				rra(a, out);
			i++;
		}
	}
	sort(a, b, r, out);
	//i = 0;
	while (i < m)
	{
		rrb(b, out);
		i++;
	}
	sort_b(a, b, m, out);
	sort_b(a, b, s, out);
}

void	sort_b(t_stack *a, t_stack *b, int size, t_output **out)
{
	int	r;
	int	s;
	int	m;
	int	i;
	int p1;
	int p2;
	int	count;

	i = 0;
	r = 0;
	s = 0;
	m = 0;
	if (size <= 3)
	{
		mini_sort_b(b, size, out);
		while (size > 0)
		{
			pa(a, b, out);
			size--;
		}
		return ;
	}
	if (is_sorted_b(b))
	{
		while (size > 0)
		{
			pa(a, b, out);
			size--;
		}
		return ;
	}
	search_pivot(b, size, &p1, &p2);
	count = 0;
	while (i < size)
	{
		if (b->stack[0] <= p1)
		{
			if (count)
			{
				rr(a, b, out);
				count--;
			}
			else
				rb(b, out);
			s++;
		}
		else if (b->stack[0] <= p2)
		{
			pa(a, b, out);
			count++;
			//ra(a);
			m++;
		}
		else
		{
			while (count)
			{
				ra(a, out);
				count--;
			}
			pa(a, b, out);
			r++;
		}
		i++;
	}
	while (count)
	{
		ra(a, out);
		count--;
	}
	i = 0;
	sort(a, b, r, out);
	i = 0;
	while (i < m)
	{
		if (i < s)
			rrr(a, b, out);
		else
			rra(a, out);
		i++;
	}
	sort(a, b, m, out);
	while (i < s)
	{
		rrb(b, out);
		i++;
	}
	sort_b(a, b, s, out);
}

/*static int	search_max(t_stack *a)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = -2147483648;
	while (i < a->size)
	{
		if (a->stack[i] >= max)
		{
			max = a->stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}*/
/*


void	first_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	m;
	int	k;

	i = 0;
	m = stack_cpy(a);
	ft_printf("%d",m);
	k = a->size;
	while (i < k)
	{
		if (a->stack[0] <= m)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	second_sort(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		
	}
}*/