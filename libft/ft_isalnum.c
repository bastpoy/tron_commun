/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:05:48 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/06 18:14:47 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalnum(int c){
if (c > 47 && c < 57 || c > 64 && c < 91 || c > 96 && c < 123){
    return (1);
} 
	return (c);
}
