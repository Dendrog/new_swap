/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:59:04 by jakim             #+#    #+#             */
/*   Updated: 2024/06/08 17:56:45 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	opti(t_output **out)
{
	t_output	*ptr;
	t_output	*tmp;

	if (!out ||!*out)
		return ;
	ptr = *out;
	while (ptr->next && ptr)
	{
		if ((!ft_strncmp(ptr->str, "pa", 4) && !ft_strncmp(ptr->next->str, "pb", 4)) || (!ft_strncmp(ptr->str, "pb", 4) && !ft_strncmp(ptr->next->str, "pa", 4)) \
		|| (!ft_strncmp(ptr->str, "ra", 4) && !ft_strncmp(ptr->next->str, "rra", 4)) || (!ft_strncmp(ptr->str, "rra", 4) && !ft_strncmp(ptr->next->str, "ra", 4)) \
		|| (!ft_strncmp(ptr->str, "rb", 4) && !ft_strncmp(ptr->next->str, "rrb", 4)) || (!ft_strncmp(ptr->str, "rrb", 4) && !ft_strncmp(ptr->next->str, "rb", 4)) \
		|| (!ft_strncmp(ptr->str, "rr", 4) && !ft_strncmp(ptr->next->str, "rrr", 4)) || (!ft_strncmp(ptr->str, "rrr", 4) && !ft_strncmp(ptr->next->str, "rr", 4)))
		{
			tmp = ptr;
			if (ptr->prev)
			{
				ptr = ptr->prev;
				ptr->next = ptr->next->next->next;
				if (ptr->next)
					ptr->next->prev = ptr;
			}
			else
			{
				ptr = ptr->next->next;
				if (ptr)
					ptr->prev = ptr->prev->prev->prev;
			}
			free(tmp->next);
			free(tmp);
		}
		else if ((!ft_strncmp(ptr->str, "ra", 4) && !ft_strncmp(ptr->next->str, "rb", 4)) || (!ft_strncmp(ptr->str, "rb", 4) && !ft_strncmp(ptr->next->str, "ra", 4)))
		{
			tmp = ptr->next;
			ptr->next = ptr->next->next;
			if (ptr->next)
					ptr->next->prev = ptr;
			ptr->str = "rr";
			free(tmp);
		}
		else if ((!ft_strncmp(ptr->str, "rra", 4) && !ft_strncmp(ptr->next->str, "rrb", 4)) || (!ft_strncmp(ptr->str, "rrb", 4) && !ft_strncmp(ptr->next->str, "rra", 4)))
		{
			tmp = ptr->next;
			ptr->next = ptr->next->next;
			if (ptr->next)
					ptr->next->prev = ptr;
			ptr->str = "rrr";
			free(tmp);
		}
		else if ((!ft_strncmp(ptr->str, "rr", 4) && !ft_strncmp(ptr->next->str, "rrb", 4)) || (!ft_strncmp(ptr->str, "rrb", 4) && !ft_strncmp(ptr->next->str, "rr", 4)))
		{
			tmp = ptr->next;
			ptr->next = ptr->next->next;
			if (ptr->next)
					ptr->next->prev = ptr;
			ptr->str = "ra";
			free(tmp);
		}
		else if ((!ft_strncmp(ptr->str, "rr", 4) && !ft_strncmp(ptr->next->str, "rra", 4)) || (!ft_strncmp(ptr->str, "rra", 4) && !ft_strncmp(ptr->next->str, "rr", 4)))
		{
			tmp = ptr->next;
			ptr->next = ptr->next->next;
			if (ptr->next)
					ptr->next->prev = ptr;
			ptr->str = "rb";
			free(tmp);
		}
		else if ((!ft_strncmp(ptr->str, "rrr", 4) && !ft_strncmp(ptr->next->str, "rb", 4)) || (!ft_strncmp(ptr->str, "rb", 4) && !ft_strncmp(ptr->next->str, "rrr", 4)))
		{
			tmp = ptr->next;
			ptr->next = ptr->next->next;
			if (ptr->next)
					ptr->next->prev = ptr;
			ptr->str = "rra";
			free(tmp);
		}
		else if ((!ft_strncmp(ptr->str, "rrr", 4) && !ft_strncmp(ptr->next->str, "ra", 4)) || (!ft_strncmp(ptr->str, "ra", 4) && !ft_strncmp(ptr->next->str, "rrr", 4)))
		{
			tmp = ptr->next;
			ptr->next = ptr->next->next;
			if (ptr->next)
					ptr->next->prev = ptr;
			ptr->str = "rrb";
			free(tmp);
		}
		else
			ptr = ptr->next;
	}	
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_output *head;
	t_output *ptr;

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
	ptr = head;
	while(ptr)
	{
		ft_printf("%s\n",ptr->str);
		ptr = ptr->next;
	}
	free(b.stack);
	free(a.stack);
	lstclear(&head);
}