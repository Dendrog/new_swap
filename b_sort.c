/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:03:20 by jakim             #+#    #+#             */
/*   Updated: 2024/06/08 23:17:25 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rsrrb(t_stack *a, t_output **out)
{
	rb(a, out);
	sb(a, out);
	rrb(a, out);
}

static void	b_small(t_stack *a, t_output **out)
{
	if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] \
	&& a->stack[1] < a->stack[2])
	{
		rb(a, out);
		sb(a, out);
	}
	else if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] \
	&& a->stack[1] > a->stack[2])
		rb(a, out);
	else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] \
	&& a->stack[1] < a->stack[2])
		rrb(a, out);
	else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] \
	&& a->stack[1] > a->stack[2])
		sb(a, out);
	else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] \
	&& a->stack[1] < a->stack[2])
	{
		rrb(a, out);
		sb(a, out);
	}
}

static void	b_big(t_stack *a, t_output **out)
{
	if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] \
	&& a->stack[1] < a->stack[2])
	{
		sb(a, out);
		rsrrb(a, out);
		sb(a, out);
	}
	else if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] \
	&& a->stack[1] > a->stack[2])
	{
		sb(a, out);
		rsrrb(a, out);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] \
	&& a->stack[1] < a->stack[2])
	{
		rsrrb(a, out);
		sb(a, out);
	}
	else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] \
	&& a->stack[1] > a->stack[2])
		sb(a, out);
	else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] \
	&& a->stack[1] < a->stack[2])
		rsrrb(a, out);
}

void	mini_sort_b(t_stack *a, int size, t_output **out)
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
			b_small(a, out);
		else
			b_big(a, out);
	}
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
