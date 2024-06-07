/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:59:04 by jakim             #+#    #+#             */
/*   Updated: 2024/06/05 16:41:28 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(1);
	if (argc == 2)
		a.stack = make_stack_1(argv[1], &a.size);
	if (argc > 2)
		a.stack = make_stack_2(argc, argv, &a.size);
	dup_check(&a);
	b.stack = (int *)malloc(sizeof(int) * (a.size + 5));
	null_guard(b.stack);
	b.size = 0;
	sort(&a, &b, a.size);
	/*for (int i = 0; i < a.size; i++)
	{
		ft_printf("%d ",a.stack[i]);
	}
	ft_printf("\n\n");
	for (int i = 0; i < b.size; i++)
	{
		ft_printf("%d ",b.stack[i]);
	}*/
	free(b.stack);
	free(a.stack);
}