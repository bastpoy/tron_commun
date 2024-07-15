#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>

std::string check_occurence(std::string line,const char *tofind, std::string tochange)
{
    std::size_t occurence;
    int i;

    occurence = line.find(tofind, 0);
    while(occurence != std::string::npos)
    {
        // i = 0;
        // while(tochange[i])
        // {
        //     line[occurence + i] = tochange[i];
        //     i++;
        // }
        line.erase(occurence, strlen(tofind));

        occurence = line.find(tofind, 0);
    }
    return(line);
}

int main(int argc, char *argv[])
{
    std::string line = "";
    const char *tofind;
    const char *tochange;
    
    if(argc != 4)
    {
        std::cout << "Wrong number of argument" << std::endl;
        return(1);
    }
    std::ifstream output(argv[1]);
    if (!output) {
        std::cout << "Failed to open file." << std::endl;
        return 1;
    }
    if(output.is_open())
    {
        while(std::getline (output, line))
        {

            std::cout << check_occurence(line, argv[2], argv[3]);
            std::cout << std::endl;
        }
    }
}
