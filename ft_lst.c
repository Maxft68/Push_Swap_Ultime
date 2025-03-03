/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxoph <maxoph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:41:30 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/03/03 13:21:50 by maxoph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *list)
{
	t_list	*temp;
	int		i;

	temp = list;
	i = 1;
	if (list == NULL)
		return (0);
	while (temp->next != list)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

t_list	*ft_lstnew(char *the_value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = ft_atoi(the_value);
	new->index = 0;
	new->block = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_list	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
		return (new);
	}
	last = (*lst)->prev;
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
	return (*lst);
}

t_list	*ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
		return (*lst);
	}
	if ((*lst)->next == *lst)
	{
		(*lst)->next = new;
		(*lst)->prev = new;
		new->next = *lst;
		new->prev = *lst;
		*lst = new;
		return (*lst);
	}
	last = (*lst)->prev;
	last->next = new;
	new->next = *lst;
	new->prev = last;
	(*lst)->prev = new;
	*lst = new;
	return (*lst);
}
