/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxoph <maxoph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:19:54 by maxoph            #+#    #+#             */
/*   Updated: 2025/03/02 23:25:06 by maxoph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid(char *s)
{
	int i;
	
	i = 0;
	if (!s || !s[0])
		return (0);
	
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int is_valid_int(char *s)
{
	long long result;
	int sign;
	int i;
	
	result = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		if ((sign == 1 && result > 2147483647) || 
			(sign == -1 && result > 2147483648))
			return (0);
		i++;
	}
	return (1);
}

int	no_duplicate(char **argv)
{
	int i;
	int j;
	int value_i;
	int value_j;

	i = 0;
	j = 0;
	while(argv[i])
	{
		value_i = ft_atoi(argv[i]);
		j = i + 1;
		while(argv[j])
		{
			value_j = ft_atoi(argv[j]);
			if (value_i == value_j)
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}

int control_all(char **argv)
{
	int i;
	
	i = 0;
	while (argv[i])
	{
		if (!is_valid(argv[i]) || !is_valid_int(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return(0);
		}
		i++;
	}
	if (!no_duplicate(argv))
	{
		ft_putstr_fd("Error\n", 2);
		return(0);
	}
	return(1);
}
