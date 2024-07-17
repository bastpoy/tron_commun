#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>

std::string check_occurence(std::string line, const char *tofind, std::string tochange)
{
    std::size_t occurence;
    const char* tochangecp = tochange.c_str();

    occurence = line.find(tofind, 0);
    while(occurence != std::string::npos)
    {
        line.erase(occurence, strlen(tofind));
        line.insert(occurence, tochange);
        occurence = line.find(tofind, occurence + strlen(tochangecp));
    }
    return(line);
}

int main(int argc, char *argv[])
{
    std::string line = "";
    const char *tofind;
    const char *tochange;
    std::string outputfile;
    
    if(argc != 4)
    {
        std::cout << "Wrong number of argument" << std::endl;
        return(1);
    }
    tofind = argv[2];
    tochange = argv[3];
    // outputfile = 
    std::ifstream input(argv[1]);
    if (!input) {
        std::cout << "Failed to open file." << std::endl;
        return 1;
    }
    std::ofstream output(argv[1].append(".replace"));
    if(input.is_open())
    {
        while(std::getline (input, line))
        {
            std::cout << check_occurence(line, tofind, tochange);
            std::cout << std::endl;
        }
    }
}
