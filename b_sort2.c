/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:23:37 by jakim             #+#    #+#             */
/*   Updated: 2024/06/09 00:25:58 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	div_type1_b(t_stack *a, t_stack *b, t_var *vars, t_output **out)
{
	if (vars->count)
	{
		rr(a, b, out);
		vars->count--;
	}
	else
		rb(b, out);
	vars->s++;
}

void	div_type2_b(t_stack *a, t_stack *b, t_var *vars, t_output **out)
{
	pa(a, b, out);
	vars->count++;
	vars->m++;
}

void	div_type3_b(t_stack *a, t_stack *b, t_var *vars, t_output **out)
{
	while (vars->count)
	{
		ra(a, out);
		vars->count--;
	}
	pa(a, b, out);
	vars->r++;
}

void	divide_b(t_stack *a, t_stack *b, t_var *vars, t_output **out)
{
	int	i;

	i = 0;
	while (i < vars->size)
	{
		if (b->stack[0] <= vars->p1)
			div_type1_b(a, b, vars, out);
		else if (b->stack[0] <= vars->p2)
			div_type2_b(a, b, vars, out);
		else
			div_type3_b(a, b, vars, out);
		i++;
	}
	while (vars->count)
	{
		ra(a, out);
		vars->count--;
	}
}

int	m_set_b(t_stack *a, t_stack *b, t_var *vars, t_output **out)
{
	int	i;

	i = 0;
	while (i < vars->m)
	{
		if (i < vars->s)
			rrr(a, b, out);
		else
			rra(a, out);
		i++;
	}
	return (i);
}
