/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:17:03 by jakim             #+#    #+#             */
/*   Updated: 2024/06/08 22:35:18 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	num_count(char *argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		if (*argv == ' ')
			i++;
		argv++;
	}
	return (i);
}

int	*make_stack_1(char *argv, int *l)
{
	int	*stack;
	int	tmp;
	int	i;

	i = 0;
	stack = (int *)malloc(sizeof(int) * (num_count(argv) + 5));
	null_guard(stack);
	while (1)
	{
		argv = ft_atoi2(argv, &tmp);
		if (argv)
			stack[i++] = tmp;
		if (!argv || !*argv)
		{
			*l = i;
			return (stack);
		}
	}
	return (NULL);
}

int	*make_stack_2(int argc, char *argv[], int *l)
{
	int		*stack;
	int		tmp;
	char	*ptr;
	int		i;

	i = 0;
	stack = (int *)malloc(sizeof(int) * (argc + 5));
	null_guard(stack);
	argv++;
	while (1)
	{
		if (*argv == NULL)
		{
			*l = i;
			return (stack);
		}
		ptr = ft_atoi2(*argv, &tmp);
		if (!ptr || *ptr)
			er();
		stack[i++] = tmp;
		argv++;
	}
}
