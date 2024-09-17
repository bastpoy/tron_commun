#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{

    if(argc <= 1)
    {
        std::cout << "Not enoug arguments" << std::endl;
        return(1);
    }
    else
    {
        std::string input = argv[1];
        std::vector<int> array;
        std::deque<int> array1;
        PmergeMe<std::vector<int> > gamberge;
        PmergeMe<std::deque<int> > gamberge1;

        if(!gamberge.addNumbers(argv))
            return (1);
        if(!gamberge1.addNumbers(argv))
            return (1);
            
        array = gamberge.getContainer();
        array1 = gamberge1.getContainer();

        std::clock_t start = std::clock();
        gamberge.algorithm(array, 0, array.size() - 1);
        gamberge.printArray(array);
        std::clock_t end = std::clock();
        double elapsed = double(end - start);
        std::cout << "Time to process a range of " << array.size() << " elements with std::vector: " << elapsed << " us" << std::endl;
        
        start = std::clock();
        gamberge1.algorithm(array1, 0, array.size() - 1);
        gamberge1.printArray(array1);
        end = std::clock();
        elapsed = double(end - start);
        std::cout << "Time to process a range of " << array1.size() << " elements with std::deque: " << elapsed << " us" << std::endl;
    }    
}