/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:35:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/22 14:09:56 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 1;
    if (argc == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
        return (1);
    }
    while (argv[j])
    {
        i = 0;
        while (argv[j][i])
        {
            if ((int)argv[j][i] > 96 && (int)argv[j][i] < 123)
                argv[j][i] = argv[j][i] - 32;
            cout << argv[j][i];
            i++;
        }
        j++;
    }
    cout << endl;
    return (0);
}