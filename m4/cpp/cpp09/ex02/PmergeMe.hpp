#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <ctime>

template <typename Container>
class PmergeMe
{
    private:
        Container merge;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);

        void sort(Container &array, int min, int max);
        void merge_insert(Container &array, int min, int max);
        void algorithm(Container &array, int min, int max);
        
        bool addNumbers(char *argv[]);
        Container &getContainer();
        void printArray(Container array);
        
};

template <typename Container>
PmergeMe<Container>::PmergeMe()
{}
template <typename Container>
PmergeMe<Container>::~PmergeMe()
{}
template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe<Container> &copy)
{
    if(this != &copy)
    {
        this->merge = copy.merge;
    }
    return (*this);
}

template <typename Container>
bool PmergeMe<Container>::addNumbers(char *argv[])
{
    int i = 0;
    while(argv[i])
    {
        char *endptr = NULL;
        long num = strtol(argv[i] , &endptr, 0);

        if(*endptr != '\0')
        {
            i++;
            continue;
        }
        else
        {
            this->merge.push_back(num);
        }
        i++;
    }
    return (true);
}

// std::vector<int> generateJacobsthal(int count) {
//     std::vector<int> jacobsthal;

//     if (count <= 0) {
//         return jacobsthal;
//     }
//     jacobsthal.push_back(0);
//     if (count == 1) {
//         return jacobsthal;
//     }
//     jacobsthal.push_back(1);
//     if (count == 2) {
//         return jacobsthal;
//     }

//     for (int i = 2; i < count; ++i) {
//         int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
//         if(next < 0)
//             return (jacobsthal);
//         jacobsthal.push_back(next);
//     }

//     return jacobsthal;
// }

template <typename Container>
void PmergeMe<Container>::sort(Container &array, int min, int max)
{
    if(max - min == 1)
    {
        if(array[min] > array[max])
        {
            std::swap(array[min], array[max]);
        }
    }
    else if(max - min == 2)
    {
        if(array[min] > array[max - 1])
        {
            std::swap(array[min], array[max - 1]);
        }
        if(array[max - 1] > array[max])
        {
            std::swap(array[max - 1], array[max]);
        }
        if(array[min] > array[max - 1])
        {
            std::swap(array[min], array[max - 1]);
        }
    }
}
template <typename Container>
void PmergeMe<Container>::merge_insert(Container &array, int min, int max)
{
    int highmiddle = ((max + min) / 2) + 1; // middle entre low et high
    int lowmiddle = (highmiddle - 1 + min) / 2; 
    int extrem = 0;

    while(highmiddle <= max)
    {
        if((array[highmiddle] >= array[lowmiddle] && 
            array[highmiddle] <= array[lowmiddle + 1]) || 
            array[highmiddle] < array[min] ||
            array[highmiddle] > array[highmiddle - 1])
        {
            int number = array[highmiddle];
            if(array[highmiddle] >= array[lowmiddle] && array[highmiddle] <= array[lowmiddle + 1])
            {
                array.erase(array.begin() + highmiddle);
                array.insert(array.begin() + lowmiddle + 1, number);    
            }
            else if(array[highmiddle] < array[min])
            {
                array.erase(array.begin() + highmiddle);
                array.insert(array.begin() + min, number);
            }
            extrem = 0;
            highmiddle++;
            lowmiddle = (highmiddle - 1 + min) / 2;
            // printArray(array);
        }
        else if(array[highmiddle] < array[lowmiddle])
        {
            // std::cout << "dans inferieur" << std::endl;
            // std::cout << "value: " << array[highmiddle]<< " indice high: " << highmiddle << " indice low: " << lowmiddle << " value: " << array[lowmiddle] << " et min " << min << " et max " << max << std::endl; 
            // printArray(array);
            lowmiddle = (lowmiddle + extrem) / 2;
            if(lowmiddle < min )
                lowmiddle = min;
        }
        else if(array[highmiddle] > array[lowmiddle + 1])
        {
            // std::cout << "dans superieur" << std::endl;
            // std::cout << "value: " << array[highmiddle]<< " indice high: " << highmiddle << " indice low: " << lowmiddle << " value: " << array[lowmiddle] << " et min " << min << std::endl; 
            extrem = lowmiddle;
            lowmiddle = (highmiddle + lowmiddle) / 2;
        }
        // std::cout << array[highmiddle] << std::endl;
    }    
}
template <typename Container>
void PmergeMe<Container>::algorithm(Container &array, int min, int max)
{
    if(max - min > 2)
    {
        int middle = (max + min) / 2; // trouver le milieu de chaque intervalle
        algorithm(array, min, middle); // le cote min de la division par deux
        algorithm(array, middle + 1, max); // le cote max de la division par deux;
        // std::cout << "le min " << min << " et le max " << max << std::endl;
        // printArray(array);
        merge_insert(array, min, max);
    }
    else
        sort(array, min, max);
}

template <typename Container>
Container &PmergeMe<Container>::getContainer()
{
    return (this->merge);
}
template <typename Container>
void PmergeMe<Container>::printArray(Container array)
{
    for(size_t i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
#endif