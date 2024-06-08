/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:59:04 by jakim             #+#    #+#             */
/*   Updated: 2024/06/08 23:14:21 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	oper_cmp(t_output **out, char *str1, char *str2)
{
	t_output	*ptr;

	ptr = *out;
	if ((!ft_strncmp(ptr->str, str1, 4) \
	&& !ft_strncmp(ptr->next->str, str2, 4)) \
		|| (!ft_strncmp(ptr->str, str2, 4) \
		&& !ft_strncmp(ptr->next->str, str1, 4)))
	{
		return (1);
	}
	else
		return (0);
}

static void	remove(t_output **out)
{
	t_output	*tmp;

	tmp = *out;
	if ((*out)->prev)
	{
		(*out) = (*out)->prev;
		(*out)->next = (*out)->next->next->next;
		if ((*out)->next)
			(*out)->next->prev = (*out);
	}
	else
	{
		(*out) = (*out)->next->next;
		if ((*out))
			(*out)->prev = (*out)->prev->prev->prev;
	}
	free(tmp->next);
	free(tmp);
}

static void	change(t_output **out, char *str)
{
	t_output	*tmp;

	tmp = (*out)->next;
	(*out)->next = (*out)->next->next;
	if ((*out)->next)
		(*out)->next->prev = (*out);
	(*out)->str = str;
	free(tmp);
}

static void	opti(t_output **out)
{
	t_output	*ptr;

	if (!out ||!*out)
		return ;
	ptr = *out;
	while (ptr->next && ptr)
	{
		if (oper_cmp(&ptr, "pa", "pb") || oper_cmp(&ptr, "ra", "rra") \
		|| oper_cmp(&ptr, "rb", "rrb") || oper_cmp(&ptr, "rr", "rrr"))
			remove(&ptr);
		else if (oper_cmp(&ptr, "ra", "rb"))
			change(&ptr, "rr");
		else if (oper_cmp(&ptr, "rra", "rrb"))
			change(&ptr, "rrr");
		else if (oper_cmp(&ptr, "rr", "rrb"))
			change(&ptr, "ra");
		else if (oper_cmp(&ptr, "rr", "rra"))
			change(&ptr, "rb");
		else if (oper_cmp(&ptr, "rrr", "rb"))
			change(&ptr, "rra");
		else if (oper_cmp(&ptr, "rrr", "ra"))
			change(&ptr, "rrb");
		else
			ptr = ptr->next;
	}	
}

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;
	t_output	*head;

	head = NULL;
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
		sort(&a, &b, a.size, &head);
	opti(&head);
	print_oper(head);
	free(b.stack);
	free(a.stack);
	lstclear(&head);
}
