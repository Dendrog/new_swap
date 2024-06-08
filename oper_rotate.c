/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:42:04 by jakim             #+#    #+#             */
/*   Updated: 2024/06/08 15:54:15 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *a)
{
	int	i;

	i = 0;
	a->stack[a->size] = a->stack[0];
	while (i < a->size)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
}

void	ra(t_stack *a, t_output **out)
{
	rotate(a);
	lstadd_back(out, lstnew("ra"));
	//ft_printf("ra\n");
}

void	rb(t_stack *b, t_output **out)
{
	rotate(b);
	lstadd_back(out, lstnew("rb"));
	//ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b, t_output **out)
{
	rotate(a);
	rotate(b);
	lstadd_back(out, lstnew("rr"));
	//ft_printf("rr\n");
}
