/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_guard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:33:15 by jakim             #+#    #+#             */
/*   Updated: 2024/06/11 12:31:32 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	null_guard(int	*ptr)
{
	if (!ptr)
		exit(1);
}

void	er(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	dup_check(t_stack *a)
{
	int	i;
	int	k;

	i = 0;
	while (i < a->size)
	{
		k = i + 1;
		while (k < a->size)
		{
			if (a->stack[i] == a->stack[k])
				er();
			k++;
		}
		i++;
	}
}

void	print_oper(t_output *ptr)
{
	while (ptr)
	{
		ft_printf("%s\n", ptr->str);
		ptr = ptr->next;
	}
}

int	check_space(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}
