/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxoph <maxoph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:21:07 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/03/03 13:32:46 by maxoph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack, int print_ra)
{
	if (!*stack || !stack)
		return ;
	*stack = (*stack)->next;
	if (print_ra)
		ft_printf("ra\n");
}

void	rotate_b(t_list **stack, int print_rb)
{
	if (!*stack || !stack)
		return ;
	*stack = (*stack)->next;
	if (print_rb)
		ft_printf("rb\n");
}

void	double_rotate(t_list **stack_a, t_list **stack_b, int print_rr)
{
	if (!*stack_a || !stack_a || !*stack_b || !stack_b)
		return ;
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	if (print_rr)
		ft_printf("rr\n");
}
