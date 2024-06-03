
// int main()
// {
//     const char *ip_address = "192.0.2.1";
//     struct sockaddr_in addr;

//     // Convertit l'adresse IP de texte en structure d'adresse réseau IPv4
//     if (inet_pton(AF_INET, ip_address, &(addr.sin_addr)) <= 0)
//     {
//         perror("inet_pton");
//         exit(EXIT_FAILURE);
//     }

//     // Affiche l'adresse IP convertie
//     printf("Adresse IP convertie : %s\n", inet_ntoa(addr.sin_addr)); // Utilisation de inet_ntoa() à titre d'exemple
//     return 0;
// }
// int main()
// {
//     const char *ip_address = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";
//     struct sockaddr_in6 addr;

//     // Convertit l'adresse IP de texte en structure d'adresse réseau IPv6
//     if (inet_pton(AF_INET6, ip_address, &(addr.sin6_addr)) <= 0)
//     {
//         perror("inet_pton");
//         exit(EXIT_FAILURE);
//     }

//     // Affiche l'adresse IP convertie
//     char straddr[INET6_ADDRSTRLEN];
//     inet_ntop(AF_INET6, &(addr.sin6_addr), straddr, INET6_ADDRSTRLEN);
//     printf("Adresse IP convertie : %s\n", straddr);
//     return 0;
// }

    // for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
    //     if (ifa->ifa_addr == NULL) {
    //         continue;
    //     }
    //     if (ifa->ifa_addr->sa_family == AF_INET) {
    //     // Check if the address family is AF_INET (IPv4)
    //         struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_addr;
    //         struct sockaddr_in *netmask = (struct sockaddr_in *)ifa->ifa_netmask;

    //         // Convert IP address and netmask to strings
    //         char ip_str[INET_ADDRSTRLEN];
    //         char mask_str[INET_ADDRSTRLEN];
    //         inet_ntop(AF_INET, &addr->sin_addr, ip_str, INET_ADDRSTRLEN);
    //         inet_ntop(AF_INET, &netmask->sin_addr, mask_str, INET_ADDRSTRLEN);

    //         // Print IP address, mask address, and address family
    //         printf("Interface: %s\n", ifa->ifa_name);
    //         printf("  IP Address: %s\n", ip_str);
    //         printf("  Mask Address: %s\n", mask_str);
    //         printf("  Address Family: %d\n", ifa->ifa_addr->sa_family);
    //     }
    // }