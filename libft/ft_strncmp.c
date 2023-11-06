/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:58:43 by bpoyet            #+#    #+#             */
/*   Updated: 2023/08/16 15:13:59 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (i == n)
	{
		return (0);
	}
	while (i < n - 1 && s1[i] && s2[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int main(void)
{
	char un[]="saluT";
	char deux[]="salut";

	printf("%d\n",ft_strncmp(un, deux,5));
	printf("%d",strncmp(un, deux, 5));
}*/
