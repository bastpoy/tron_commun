/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malcolm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:06:16 by bpoyet            #+#    #+#             */
/*   Updated: 2024/06/02 21:19:40 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ifaddrs.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct hostent *hostinfo = NULL;
    struct sockaddr_in sin = {0}; 
    // const char *hostname = "www.developpez.com";
    const char *hostname = "192.168.0.109";
    char buffer[] = "data sending";
    int fdsocket;
    int n = 0;

    fdsocket = socket(AF_INET, SOCK_STREAM, 0); // socket TCP ipv4
    if(fdsocket < 0)
    {
        perror("invalid socket");
    }
    // hostinfo = gethostbyname(hostname);
    // if(!hostinfo)
    // {
    //     printf("host info nulle\n");
    //     exit(0);
    // }
    // sin.sin_addr = *(struct in_addr*)hostinfo->h_addr_list[0];
    sin.sin_addr.s_addr = inet_addr(hostname);
    sin.sin_port = htons(5000);
    sin.sin_family = AF_INET; // ipv4

    printf("Port %d\n", sin.sin_port);
    // creation du socket sur ipv4 adress et TCP

    // if(connect(fdsocket, (struct sockaddr*)&sin, sizeof(struct sockaddr)) == -1)
    // {
    //     perror("Error connection ");
    //     exit(EXIT_FAILURE);
    // }
    // else
    //     printf("Connected\n");
    if(send(fdsocket, buffer, strlen(buffer), 0) == -1)
    {
        perror("Error sending ");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Sending data...\n");
    }
    printf("Closing connection\n");
    sleep(1);
    if((n = recv(fdsocket, buffer, sizeof(buffer) - 1, 0)) < 0)
    {
        perror("Error response ");
        exit(EXIT_FAILURE);
    }
    else
    {
        buffer[n] = '\0';
        printf("Data received: %s\n", buffer);
    }
    close(fdsocket);
    return 0;
}

