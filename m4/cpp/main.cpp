/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:28:01 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/22 16:51:22 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (1);

    int number = 6;
    string test = "re";

    int &ref(number);

    cin >> number;
    cout << "la string" << endl;
    cin.ignore();
    getline(cin, test);

    cout << "re " << number << " " << test << endl;
    return (0);
}