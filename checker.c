/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 04:04:28 by jakim             #+#    #+#             */
/*   Updated: 2024/06/11 12:33:15 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	double_oper(t_stack *a, t_stack *b, int i)
{
	if (i == 1)
	{
		swap(a);
		swap(b);
	}
	else if (i == 2)
	{
		rotate(a);
		rotate(b);
	}
	else if (i == 3)
	{
		reverse(a);
		reverse(b);
	}
}

static void	input_type(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 10))
		swap(a);
	else if (!ft_strncmp(str, "sb\n", 10))
		swap(b);
	else if (!ft_strncmp(str, "ss\n", 10))
		double_oper(a, b, 1);
	else if (!ft_strncmp(str, "pa\n", 10))
		push(a, b);
	else if (!ft_strncmp(str, "pb\n", 10))
		push(b, a);
	else if (!ft_strncmp(str, "ra\n", 10))
		rotate(a);
	else if (!ft_strncmp(str, "rb\n", 10))
		rotate(b);
	else if (!ft_strncmp(str, "rr\n", 10))
		double_oper(a, b, 2);
	else if (!ft_strncmp(str, "rra\n", 10))
		reverse(a);
	else if (!ft_strncmp(str, "rrb\n", 10))
		reverse(b);
	else if (!ft_strncmp(str, "rrr\n", 10))
		double_oper(a, b, 3);
	else
		er();
}

static void	check(t_stack *a, t_stack *b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			return ;
		input_type(a, b, str);
		free(str);
	}
}

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;

	if (argc < 2)
		exit(1);
	if (argc == 2 && (!ft_strlen(argv[1]) || check_space(argv[1])))
		er();
	if (argc == 2)
		a.stack = make_stack_1(argv[1], &a.size);
	if (argc > 2)
		a.stack = make_stack_2(argc, argv, &a.size);
	dup_check(&a);
	b.stack = (int *)malloc(sizeof(int) * (a.size + 5));
	null_guard(b.stack);
	b.size = 0;
	check(&a, &b);
	if (!b.size && is_sorted(&a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(b.stack);
	free(a.stack);
}
