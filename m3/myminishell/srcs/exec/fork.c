/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:17:34 by bpoyet            #+#    #+#             */
/*   Updated: 2024/06/06 17:56:10 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	do_fork(t_tree *tree, pid_t pid)
{
	pid = fork();
	if (pid < 0)
	{
		err_free_all(tree);
	}
	return (pid);
}
