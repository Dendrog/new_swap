/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:02:30 by jakim             #+#    #+#             */
/*   Updated: 2024/06/09 01:04:29 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rsrra(t_stack *a, t_output **out)
{
	ra(a, out);
	sa(a, out);
	rra(a, out);
}

static void	a_small(t_stack *a, t_output **out)
{
	if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] \
	&& a->stack[1] > a->stack[2])
	{
		rra(a, out);
		sa(a, out);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] \
	&& a->stack[1] < a->stack[2])
		sa(a, out);
	else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] \
	&& a->stack[1] > a->stack[2])
		rra(a, out);
	else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] \
	&& a->stack[1] < a->stack[2])
		ra(a, out);
	else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] \
	&& a->stack[1] > a->stack[2])
	{
		ra(a, out);
		sa(a, out);
	}
}

static void	a_big(t_stack *a, t_output **out)
{
	if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] \
	&& a->stack[1] > a->stack[2])
		rsrra(a, out);
	else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] \
	&& a->stack[1] < a->stack[2])
		sa(a, out);
	else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] \
	&& a->stack[1] > a->stack[2])
	{
		rsrra(a, out);
		sa(a, out);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] \
	&& a->stack[1] < a->stack[2])
	{
		sa(a, out);
		rsrra(a, out);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] \
	&& a->stack[1] > a->stack[2])
	{
		sa(a, out);
		rsrra(a, out);
		sa(a, out);
	}
}

void	mini_sort(t_stack *a, int size, t_output **out)
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
			a_small(a, out);
		else
			a_big(a, out);
	}
}

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
