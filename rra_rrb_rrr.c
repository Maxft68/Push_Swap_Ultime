/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxoph <maxoph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:44:29 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/03/03 16:12:08 by maxoph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **stack, int print_rra)
{
	if (!*stack || !stack)
		return ;
	*stack = (*stack)->prev;
	if (print_rra)
		ft_printf("rra\n");
	return ;
}

void	reverse_rotate_b(t_list **stack, int print_rrb)
{
	if (!*stack || !stack)
		return ;
	*stack = (*stack)->prev;
	if (print_rrb)
		ft_printf("rrb\n");
	return ;
}

void	dual_reverse_rotate(t_list **stack_a, t_list **stack_b, int print_rrr)
{
	if (!*stack_a || !stack_a || !*stack_b || !stack_b)
		return ;
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	if (print_rrr)
		ft_printf("rrr\n");
	return ;
}
