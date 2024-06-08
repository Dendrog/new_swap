/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:10:20 by jakim             #+#    #+#             */
/*   Updated: 2024/06/09 00:26:32 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	div_type1_a(t_stack *a, t_stack *b, t_var *vars, t_output **out)
{
	while (vars->count)
	{
		rb(b, out);
		vars->count--;
	}
	pb(a, b, out);
	vars->s++;
}

void	div_type2_a(t_stack *a, t_stack *b, t_var *vars, t_output **out)
{
	pb(a, b, out);
	vars->count++;
	vars->m++;
}

void	div_type3_a(t_stack *a, t_stack *b, t_var *vars, t_output **out)
{
	if (vars->count)
	{
		rr(a, b, out);
		vars->count--;
	}
	else
		ra(a, out);
	vars->r++;
}

void	divide_a(t_stack *a, t_stack *b, t_var *vars, t_output **out)
{
	int	i;

	i = 0;
	while (i < vars->size)
	{
		if (a->stack[0] <= vars->p1)
			div_type1_a(a, b, vars, out);
		else if (a->stack[0] <= vars->p2)
			div_type2_a(a, b, vars, out);
		else
			div_type3_a(a, b, vars, out);
		i++;
	}
	while (vars->count)
	{
		rb(b, out);
		vars->count--;
	}
}

int	r_set_a(t_stack *a, t_stack *b, t_var *vars, t_output **out)
{
	int	i;

	i = 0;
	if (a->size != vars->r)
	{
		while (i < vars->r)
		{
			if (i < vars->m)
				rrr(a, b, out);
			else
				rra(a, out);
			i++;
		}
	}
	return (i);
}
