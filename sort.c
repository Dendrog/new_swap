/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:31:21 by jakim             #+#    #+#             */
/*   Updated: 2024/06/09 00:25:30 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_cpy(t_stack *a, int size)
{
	t_stack	*st;
	int		i;

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
	int		i;
	int		k;
	t_stack	*a;

	a = stack_cpy(st, size);
	i = 0;
	while (i < size - 1)
	{
		k = 0;
		while (k < size - 1 - i)
		{
			if (a->stack[k] > a->stack[k + 1])
				swap_value(&(a->stack[k]), &(a->stack[k + 1]));
			k++;
		}
		i++;
	}
	*p1 = a->stack[size / 3 - 1];
	*p2 = a->stack[size / 3 * 2 - 1];
	free(a->stack);
	free(a);
}

void	sort(t_stack *a, t_stack *b, int size, t_output **out)
{
	t_var	vars;
	int		i;

	set_vars(&vars, size);
	if (size <= 3)
	{
		mini_sort(a, size, out);
		return ;
	}
	search_pivot(a, size, &(vars.p1), &(vars.p2));
	if (is_sorted(a))
		return ;
	divide_a(a, b, &vars, out);
	i = r_set_a(a, b, &vars, out);
	sort(a, b, vars.r, out);
	while (i < vars.m)
	{
		rrb(b, out);
		i++;
	}
	sort_b(a, b, vars.m, out);
	sort_b(a, b, vars.s, out);
}

static void	move(t_stack *a, t_stack *b, int size, t_output **out)
{
	if (size <= 3)
		mini_sort_b(b, size, out);
	while (size > 0)
	{
		pa(a, b, out);
		size--;
	}
}

void	sort_b(t_stack *a, t_stack *b, int size, t_output **out)
{
	t_var	vars;
	int		i;

	set_vars(&vars, size);
	if (size <= 3 || is_sorted_b(b))
	{
		move(a, b, size, out);
		return ;
	}
	search_pivot(b, size, &(vars.p1), &(vars.p2));
	divide_b(a, b, &vars, out);
	sort(a, b, vars.r, out);
	i = m_set_b(a, b, &vars, out);
	sort(a, b, vars.m, out);
	while (i < vars.s)
	{
		rrb(b, out);
		i++;
	}
	sort_b(a, b, vars.s, out);
}
