#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::string string = "";
    if(argc != 2)
    {
        std::cout << "Wrong number of argument" << std::endl;
        return(1);
    }
    std::ofstream output(argv[1]);
    if (!output) {
        std::cout << "Failed to open output file." << std::endl;
        return 1;
    }
    std::getline(std::cin, string);
    output << string ;
}