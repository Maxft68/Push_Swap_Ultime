/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxoph <maxoph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:29:09 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/03/03 01:00:01 by maxoph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void choose_algo(t_list **head, t_list **head2)
{
	int size;
	
	size = ft_lstsize(*head);
	if (control(*head) != 1 && size != 1 && size < 4)
		algo_three(head);
	else if (!control(*head) && size != 1 && size < 6)
		algo_five(head, head2);
	else if (!control(*head) && size == 6)
	{
		big_algo(head, head2, create_block(head, 3)); 
		big_algo_back_to_head(head, head2);
	}
	else if (!control(*head) && size > 6 && size < 151)
	{
		big_algo(head, head2, create_block(head, 3.5)); 
		big_algo_back_to_head(head, head2);
	}
	else if (!control(*head) && size >= 151)
	{
		big_algo(head, head2, create_block(head, 8.6));
		big_algo_back_to_head(head, head2);
	}
	return;
}
void do_node(char **argv, char **argvsplit, t_list **head, t_list **head2)
{
	int i;
	t_list *new_node;
	
	i = 0;
	while (argv[i])
	{
		new_node = ft_lstnew(argv[i]);
		if (!new_node)
			return(clear_all(head, head2, argvsplit), exit(EXIT_FAILURE));
		ft_lstadd_back(head, new_node);
		i++;
	}
	ft_index(head);
	return;
}

int main(int argc, char **argv)
{
	t_list *head;
	t_list *head2;
	char **argvsplit;
	
	head = NULL;
	head2 = NULL;
	argvsplit = NULL;
	if (argc == 1)
		return(0);
	if (argc == 2)
	{
		argvsplit = ft_split(argv[1], ' ');
		if (!argvsplit || !argvsplit[0] || !control_all(argvsplit))
			return (clear_all(&head, &head2, argvsplit), exit(EXIT_FAILURE), 0);
		argv = argvsplit;
		do_node(argv, argvsplit, &head, &head2);
	}
	else if (argc > 2)
	{
		if (!control_all(argv + 1))
			return (clear_all(&head, &head2, argvsplit), exit(EXIT_FAILURE), 0);
		do_node(argv + 1, argvsplit, &head, &head2);
	}
	choose_algo(&head, &head2);
	return (clear_all(&head, &head2, argvsplit), 0);
}
