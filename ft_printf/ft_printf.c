/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:03:26 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/18 16:25:53 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int ft_printf(const char *entry, ...)
{
	size_t lenstr;
	char *str;
	int i;

	i = 0;
	lenstr = ft_strlen(lenstr);
	str = (char*)malloc(sizeof(char) * (lenstr + ));
	if(!str)
		return (0);
	while(str[i])
	{
		if(ft_strchr(str[i], '%'))
		{

		}
	}
}



// Pouvoir manipuler ma chaine. Il faut que je puisse print les caracteres
// et tout ce qui est precede de %(i,d,ld) doit etre remplacer par la valeur passe en parametre

// pouvoir detecter le nieme %d et l'associer au nieme parametre.
// je peux faire ca en utilisant les listes chainees