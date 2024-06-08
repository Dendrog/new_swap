/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:51:40 by jakim             #+#    #+#             */
/*   Updated: 2024/06/08 16:30:53 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	minus(char **nptr, long long *sign)
{
	if (**nptr == '-')
		(*sign) *= -1;
	if (**nptr == '-')
		(*nptr)++;
}

char	*ft_atoi2(char *nptr, int	*r)
{
	long long	sign;
	long long	result;
	int			flag;

	flag = 0;
	result = 0;
	sign = 1;
	while (*nptr == '\f' || *nptr == '\n' || *nptr == '\r' || \
		*nptr == '\t' || *nptr == '\v' || *nptr == ' ')
		nptr++;
	minus(&nptr, &sign);
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (long long)(*(nptr++) - '0');
		flag = 1;
	}
	if ((*nptr != ' ' && *nptr != '\0') || (!flag && sign == -1))
		er();
	if (result * sign > 2147483647 || result * sign < -2147483648)
		er();
	if (!flag)
		return (NULL);
	*r = (int)(result * sign);
	return (nptr);
}

void	lstadd_back(t_output **lst, t_output *new)
{
	t_output	*ptr;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
}

t_output	*lstnew(char *content)
{
	t_output	*ptr;

	ptr = (t_output *)malloc(sizeof(t_output));
	if (!ptr)
		return (NULL);
	ptr->str = content;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

void	lstclear(t_output **lst)
{
	t_output	*ptr;
	t_output	*tmp;
	ptr = *lst;
	if (!*lst || !lst)
		return ;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}