/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:35:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/09 17:21:15 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 1;
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
            if ((int)argv[j][i] > 96 && (int)argv[j][i] < 123)
                argv[j][i] = argv[j][i] - 32;
            std::cout << argv[j][i];
            i++;
        }
        j++;
    }
    std::cout << std::endl;
    return (0);
}