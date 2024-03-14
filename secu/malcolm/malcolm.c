/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malcolm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:06:16 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/14 18:20:53 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <unistd.h>

int main()
{
    const char *interface_name = "enp4s0f0";
    unsigned int index = if_nametoindex(interface_name);
    int uid = getuid();

    printf("l'id vaut %d\n", uid);
    if (index == 0)
    {
        printf("Interface '%s' not found or error occurred.\n", interface_name);
    }
    else
    {
        printf("Index of interface '%s' is: %u\n", interface_name, index);
    }

    return 0;
}