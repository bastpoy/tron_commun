/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:35:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/10 22:59:58 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    size_t i = 0;
    size_t j = 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    while (argv[j])
    {
        i = 0;
        while (argv[j][i])
        {
            std::cout << (char)toupper(argv[j][i]);
            i++;
        }
        j++;
    }
    std::cout << std::endl;
    return (0);
}
