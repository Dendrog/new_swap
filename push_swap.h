/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:14:18 by jakim             #+#    #+#             */
/*   Updated: 2024/06/11 12:26:17 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_stack
{
	int	*stack;
	int	size;
}				t_stack;

typedef struct s_output
{
	char			*str;
	struct s_output	*next;
	struct s_output	*prev;
}				t_output;

typedef struct s_var
{
	int	r;
	int	s;
	int	m;
	int	p1;
	int	p2;
	int	count;
	int	size;
}				t_var;

void		null_guard(int	*ptr);
void		er(void);
int			*make_stack_1(char *argv, int *l);
char		*ft_atoi2(char *nptr, int	*r);
int			*make_stack_2(int argc, char *argv[], int *l);
void		pb(t_stack *a, t_stack *b, t_output **out);
void		pa(t_stack *a, t_stack *b, t_output **out);
void		sb(t_stack *b, t_output **out);
void		sa(t_stack *a, t_output **out);
void		ra(t_stack *a, t_output **out);
void		rb(t_stack *b, t_output **out);
void		rr(t_stack *a, t_stack *b, t_output **out);
void		rra(t_stack *a, t_output **out);
void		rrb(t_stack *b, t_output **out);
void		rrr(t_stack *a, t_stack *b, t_output **out);
void		dup_check(t_stack *a);
void		sort(t_stack *a, t_stack *b, int size, t_output **out);
void		sort_b(t_stack *a, t_stack *b, int size, t_output **out);
int			is_sorted(t_stack *a);
void		lstadd_back(t_output **lst, t_output *new);
t_output	*lstnew(char *content);
void		lstclear(t_output **lst);
void		print_oper(t_output *ptr);
void		swap_value(int *a, int *b);
void		mini_sort(t_stack *a, int size, t_output **out);
void		mini_sort_b(t_stack *a, int size, t_output **out);
int			is_sorted(t_stack *a);
int			is_sorted_b(t_stack *a);
void		set_vars(t_var *vars, int size);
void		div_type1_a(t_stack *a, t_stack *b, t_var *vars, t_output **out);
void		div_type2_a(t_stack *a, t_stack *b, t_var *vars, t_output **out);
void		div_type3_a(t_stack *a, t_stack *b, t_var *vars, t_output **out);
void		divide_a(t_stack *a, t_stack *b, t_var *vars, t_output **out);
int			r_set_a(t_stack *a, t_stack *b, t_var *vars, t_output **out);
void		div_type1_b(t_stack *a, t_stack *b, t_var *vars, t_output **out);
void		div_type2_b(t_stack *a, t_stack *b, t_var *vars, t_output **out);
void		div_type3_b(t_stack *a, t_stack *b, t_var *vars, t_output **out);
void		divide_b(t_stack *a, t_stack *b, t_var *vars, t_output **out);
int			m_set_b(t_stack *a, t_stack *b, t_var *vars, t_output **out);
void		push(t_stack *a, t_stack *b);
void		reverse(t_stack *a);
void		rotate(t_stack *a);
void		swap(t_stack *a);
int			check_space(char *str);

#endif