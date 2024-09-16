#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> merge;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);

        bool addNumbers(char *argv[]);
        std::vector<int> &getVector();
        void print();
        
        void algorithm(std::vector<int> &array, int min, int max);
        std::vector<int> insertionSort(int pair);
};

void sort(std::vector<int> &array, int min, int max);
void merge_insert(std::vector<int> &array, int min, int max);
void printArray(std::vector<int> array);

#endif