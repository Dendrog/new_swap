/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:51:40 by jakim             #+#    #+#             */
/*   Updated: 2024/05/30 02:29:00 by jakim            ###   ########.fr       */
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
