/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:31:21 by jakim             #+#    #+#             */
/*   Updated: 2024/06/08 07:19:29 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	is_sorted(t_stack *a)
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
}*/

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

static void	mini_sort(t_stack *a, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (a->stack[0] > a->stack[1])
			sa(a);
	}
	else if (size == 3)
	{
		if (size == a->size)
		{
			if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] > a->stack[2])
			{
				ra(a);
				sa(a);
				rra(a);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
				sa(a);
			else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
				rra(a);
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2])
				ra(a);
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
			{
				ra(a);
				sa(a);
			}
		}
		else
		{
			if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] > a->stack[2])
			{
				ra(a);
				sa(a);
				rra(a);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
				sa(a);
			else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
			{
				ra(a);
				sa(a);
				rra(a);
				sa(a);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2])
			{
				sa(a);
				ra(a);
				sa(a);
				rra(a);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
			{
				sa(a);
				ra(a);
				sa(a);
				rra(a);
				sa(a);
			}
		}
	}
}

static void	mini_sort_b(t_stack *a, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (a->stack[0] < a->stack[1])
			sb(a);
	}
	else if (size == 3)
	{
		if (size == a->size)
		{
			if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
			{
				rb(a);
				sb(a);
			}
			else if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] > a->stack[2])
			{
				rb(a);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
				rrb(a);
			else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
				sb(a);
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2])
			{
				rb(a);
				sb(a);
				rrb(a);
			}
		}
		else
		{
			if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
			{
				sb(a);
				rb(a);
				sb(a);
				rrb(a);
				sb(a);
			}
			else if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] > a->stack[2])
			{
				sb(a);
                rb(a);
                sb(a);
                rrb(a);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
			{
				rb(a);
                sb(a);
                rrb(a);
                sb(a);
			}
			else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
			{
				sb(a);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2])
			{
				rb(a);
                sb(a);
                rrb(a);
			}
		}
	}
}

void	sort(t_stack *a, t_stack *b, int size)
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
		mini_sort(a, size);
		return ;
	}
	search_pivot(a, size, &p1, &p2);
	count = 0;
	while (i < size)
	{
		if (a->stack[0] <= p1)
		{
			while (count)
			{
				rb(b);
				count--;
			}
			pb(a, b);
			s++;
		}
		else if (a->stack[0] <= p2)
		{
			pb(a, b);
			count++;
			//rb(b);
			m++;
		}
		else
		{
			if (count)
			{
				rr(a, b);
				count--;
			}
			else
				ra(a);
			r++;
		}
		i++;
	}
	while (count)
	{
		rb(b);
		count--;
	}
	i = 0;
	if (a->size != r)
	{
		while (i < r)
		{
			if (i < m)
				rrr(a, b);
			else
				rra(a);
			i++;
		}
	}
	sort(a, b, r);
	//i = 0;
	while (i < m)
	{
		rrb(b);
		i++;
	}
	sort_b(a, b, m);
	sort_b(a, b, s);
}

void	sort_b(t_stack *a, t_stack *b, int size)
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
		mini_sort_b(b, size);
		while (size > 0)
		{
			pa(a, b);
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
				rr(a, b);
				count--;
			}
			else
				rb(b);
			s++;
		}
		else if (b->stack[0] <= p2)
		{
			pa(a, b);
			count++;
			//ra(a);
			m++;
		}
		else
		{
			while (count)
			{
				ra(a);
				count--;
			}
			pa(a, b);
			r++;
		}
		i++;
	}
	while (count)
	{
		ra(a);
		count--;
	}
	i = 0;
	sort(a, b, r);
	i = 0;
	while (i < m)
	{
		if (i < s)
			rrr(a, b);
		else
			rra(a);
		i++;
	}
	sort(a, b, m);
	while (i < s)
	{
		rrb(b);
		i++;
	}
	sort_b(a, b, s);
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