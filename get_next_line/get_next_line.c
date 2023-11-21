/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:03:24 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/21 17:29:41 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h> 

char *get_next_line(int fd)
{
	char *buffer;
	
	
	return ("yo");
}
int main(void)
{
	int fd;

	fd = open("text.txt",O_RDONLY);
	get_next_line(fd);
	close(fd);
}