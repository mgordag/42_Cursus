/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_del_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:40:16 by mgordag           #+#    #+#             */
/*   Updated: 2022/10/17 22:40:17 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_list_left_side(t_syntax_tree **del)
{
	t_syntax_tree	*temp;

	temp = del[0];
	while (temp->left)
		temp = temp->left;
	while (temp != del[0])
	{
		temp = temp->prev;
		del_s_syntax_tree(temp->left);
		temp->left = NULL;
		if (temp->right && temp != del[0])
		{
			del_s_syntax_tree(temp->right);
			temp->right = NULL;
		}
	}
}

void	del_list_right_side(t_syntax_tree **del)
{
	while (del[0]->right)
	{
		del[0] = del[0]->right;
		if (del[0]->left)
		{
			del_list_left_side(del);
			del[0]->left = NULL;
		}
	}
	while (del[0]->prev)
	{
		del[0] = del[0]->prev;
		del_s_syntax_tree(del[0]->right);
		del[0]->right = NULL;
	}
}

void	del_list(t_syntax_tree **list)
{
	del_list_left_side(list);
	del_list_right_side(list);
	del_s_syntax_tree(*list);
}
