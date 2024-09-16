#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if(this != &copy)
    {
        this->merge = copy.merge;
    }
    return (*this);
}

bool PmergeMe::addNumbers(char *argv[])
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
    std::cout << std::endl;
    return (true);
}

std::vector<int> PmergeMe::insertionSort(int pair)
{
    std::vector<int> sortPair;
    size_t j = 0;
    for(size_t i = pair; i < this->merge.size(); i+=2)
    {
        j = 0;
        while(j < i)
        {
            if(this->merge[j] >= this->merge[j + 2])
            {
                std::swap(this->merge[j], this->merge[j + 2]);
            }
            j+=2;
        }
    }
    for(size_t i = pair % 2; i < this->merge.size(); i+=2)
    {
        sortPair.push_back(this->merge[i]);
    }
    return (sortPair);
}

std::vector<int> generateJacobsthal(int count) {
    std::vector<int> jacobsthal;

    if (count <= 0) {
        return jacobsthal;
    }

    jacobsthal.push_back(0);
    if (count == 1) {
        return jacobsthal;
    }

    jacobsthal.push_back(1);
    if (count == 2) {
        return jacobsthal;
    }

    for (int i = 2; i < count; ++i) {
        int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        if(next < 0)
            return (jacobsthal);
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}

void sort(std::vector<int> &array, int min, int max)
{
    // std::cout << "Dans sort le min " << min << " et le max " << max << std::endl;

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

void merge_insert(std::vector<int> &array, int min, int max)
{
    int highmiddle = ((max + min) / 2) + 1; // middle entre low et high
    int lowmiddle = (highmiddle - 1 + min) / 2; 
    int i = 0;
    // int highcp = highmiddle;
    // int lowcp = lowmiddle;

    while(highmiddle <= max)
    {
        i = 1;
        if(i == 0)
        {
            std::cout << "value: " << array[highmiddle]<< " indice high: " << highmiddle << " indice low: " << lowmiddle << std::endl; 
            printArray(array);
            // i++;
            i = 1;
        }
        if((array[highmiddle] >= array[lowmiddle] && 
            array[highmiddle] <= array[lowmiddle + 1]) || 
            array[highmiddle] < array[min] ||
            array[highmiddle] > array[max])
        {
            int number = array[highmiddle];
            array.erase(array.begin() + highmiddle);
            array.insert(array.begin() + lowmiddle + 1, number);
            highmiddle++;
            lowmiddle = (highmiddle + min) / 2; 
        }
        else if(array[highmiddle] < array[lowmiddle])
        {
            lowmiddle = lowmiddle / 2;
        }
        else if(array[highmiddle] > array[lowmiddle])
        {
            lowmiddle = (highmiddle + lowmiddle) / 2;
        }
        // std::cout << array[highmiddle] << std::endl;
        // printArray(array);
    }    
}

void PmergeMe::algorithm(std::vector<int> &array, int min, int max)
{
    if(max - min > 2)
    {
        int middle = (max + min) / 2; // trouver le milieu de chaque intervalle
        algorithm(array, min, middle); // le cote min de la division par deux
        algorithm(array, middle + 1, max); // le cote max de la division par deux;
        std::cout << "le min " << min << " et le max " << max << std::endl;
        printArray(array);
        merge_insert(array, min, max);
    }
    else
    {
        sort(array, min, max);
    }
    // je divise en deux apres je redivise en sous partie

}

std::vector<int> &PmergeMe::getVector()
{
    return (this->merge);
}

void PmergeMe::print()
{
    for(size_t i = 0; i < this->merge.size(); i++)
    {
        std::cout << this->merge[i] << " ";
    }
    std::cout << std::endl;
}

void printArray(std::vector<int> array)
{
    for(size_t i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
