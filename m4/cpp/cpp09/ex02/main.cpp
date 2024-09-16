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
        PmergeMe gamberge;

        if(!gamberge.addNumbers(argv))
            return (1);
        array = gamberge.getVector();
        gamberge.algorithm(array, 0, array.size() - 1);
    }    
}