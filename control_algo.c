/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxoph <maxoph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:14:26 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/03/03 16:10:19 by maxoph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*******************************************************************************
Control if all the list is sorted in ascending
*******************************************************************************/

int	control(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp->next != head)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
