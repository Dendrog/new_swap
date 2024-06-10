/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:54:48 by jakim             #+#    #+#             */
/*   Updated: 2024/06/11 04:20:18 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a)
{
	int	tmp;

	tmp = a->stack[0];
	a->stack[0] = a->stack[1];
	a->stack[1] = tmp;
}

void	sa(t_stack *a, t_output **out)
{
	swap(a);
	lstadd_back(out, lstnew("sa"));
}

void	sb(t_stack *b, t_output **out)
{
	swap(b);
	lstadd_back(out, lstnew("sb"));
}

void	ss(t_stack *a, t_stack *b, t_output **out)
{
	swap(a);
	swap(b);
	lstadd_back(out, lstnew("ss"));
}
