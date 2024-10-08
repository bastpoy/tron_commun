#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc > 2)
    {
        std::cout << "two much arguments" << std::endl;
        return(1);
    }
    else if(argc < 2)
    {
        std::cout << "Not enough arguments" << std::endl;
        return(1);
    }
    else
    {
        std::string input = argv[1];
        RPN stack;
        stack.algorithm(input);
    }
}

// espace tous les deux caracteres ou caracter de fin de chaine