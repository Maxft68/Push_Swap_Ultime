/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxoph <maxoph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:23:17 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/03/03 16:12:38 by maxoph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack, int print_sa)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;
	t_list	*third;

	first = *stack;
	second = (*stack)->next;
	if (!*stack || !stack || !(*stack)->next)
		return ;
	else if ((*stack)->next->next == *stack)
		*stack = second;
	else
	{
		third = (*stack)->next->next;
		last = (*stack)->prev;
		first->next = third;
		third->prev = first;
		second->next = first;
		last->next = second;
		second->prev = last;
		first->prev = second;
		*stack = second;
	}
	if (print_sa)
		ft_printf("sa\n");
}

void	swap_b(t_list **stack, int print_sb)
{
	t_list	*temp;
	t_list	*second;
	t_list	*last;
	t_list	*third;

	temp = *stack;
	second = (*stack)->next;
	if (!*stack || !stack || !(*stack)->next)
		return ;
	else if ((*stack)->next->next == *stack)
		*stack = second;
	else
	{
		third = (*stack)->next->next;
		last = (*stack)->prev;
		temp->next = third;
		third->prev = temp;
		second->next = temp;
		last->next = second;
		second->prev = last;
		temp->prev = second;
		*stack = second;
	}
	if (print_sb)
		ft_printf("sb\n");
}

void	swap_a_b(t_list **stack_a, t_list **stack_b, int print_ss)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	if (print_ss)
		ft_printf("ss\n");
	return ;
}
