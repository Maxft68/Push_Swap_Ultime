/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:42:27 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/28 15:43:54 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*******************************************************************************
Extract a node from a list before push
*******************************************************************************/

t_list	*extract_node(t_list **from)
{
	t_list	*temp;

	if (!from || !(*from))
		return (NULL);
	temp = *from;
	if (!temp->next || !temp->prev || temp->next == temp)
		*from = NULL;
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		*from = temp->next;
	}
	return (temp);
}

void	push_a(t_list **from_b, t_list **to_a, int print_pa)
{
	t_list	*new_a;

	if (!from_b || !*from_b)
		return ;
	new_a = extract_node(from_b);
	if (!to_a || !(*to_a))
	{
		new_a->next = new_a;
		new_a->prev = new_a;
	}
	else
	{
		new_a->next = *to_a;
		new_a->prev = (*to_a)->prev;
		(*to_a)->prev->next = new_a;
		(*to_a)->prev = new_a;
	}
	*to_a = new_a;
	if (print_pa)
		printf("pa\n");
}

void	push_b(t_list **from_a, t_list **to_b, int print_pb)
{
	t_list	*new_a;

	if (!from_a || !*from_a)
		return ;
	new_a = extract_node(from_a);
	if (!to_b || !(*to_b))
	{
		new_a->next = new_a;
		new_a->prev = new_a;
	}
	else
	{
		new_a->next = *to_b;
		new_a->prev = (*to_b)->prev;
		(*to_b)->prev->next = new_a;
		(*to_b)->prev = new_a;
	}
	*to_b = new_a;
	if (print_pb)
		printf("pb\n");
}
