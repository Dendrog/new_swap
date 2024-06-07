/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:59:04 by jakim             #+#    #+#             */
/*   Updated: 2024/06/08 07:34:30 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(1);
	if (argc == 2 && !ft_strlen(argv[1]))
		er();
	if (argc == 2)
		a.stack = make_stack_1(argv[1], &a.size);
	if (argc > 2)
		a.stack = make_stack_2(argc, argv, &a.size);
	dup_check(&a);
	b.stack = (int *)malloc(sizeof(int) * (a.size + 5));
	null_guard(b.stack);
	b.size = 0;
	if (!is_sorted(&a))
		sort(&a, &b, a.size);
	free(b.stack);
	free(a.stack);
}