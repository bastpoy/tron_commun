/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:05:53 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/24 19:05:53 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void sum(void *num)
{
    int *ptr = num;
    ptr[2] = ptr[0] + ptr[1];
    printf("%d\n", ptr[0] + ptr[1]);
}

int main(void)
{
    pthread_t thread;
    int *fd = malloc(sizeof(int) * 3);
    fd[0] = 2;
    fd[1] = 3;
    fd[2] = 0;

    pthread_create(&thread, NULL, (void*)sum, (void *)fd);
    pthread_join(thread, NULL);
    return(0);
}

