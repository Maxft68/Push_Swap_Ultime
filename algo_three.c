/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxoph <maxoph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:33:15 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/03/03 12:59:53 by maxoph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_three(t_list **head)
{
	t_list	*a;
	t_list	*n;

	a = *head;
	n = (*head)->next;
	if (a->index < n->index)
	{
		reverse_rotate_a(head, 1);
		a = *head;
		n = (*head)->next;
	}
	else if (a->index > n->index && a->index > n->next->index)
	{
		rotate_a(head, 1);
		a = *head;
		n = (*head)->next;
	}
	if ((*head)->index > (*head)->next->index)
		swap_a(head, 1);
	return ;
}
