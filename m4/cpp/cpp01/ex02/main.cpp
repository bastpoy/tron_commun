#include <iostream>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *brainptr = &brain;
    std::string &brainref = brain;

    std::cout << "brain address: " << &brain << std::endl;
    std::cout << "brainptr: " << brainptr << std::endl;
    std::cout << "brainref: " << &brainref << std::endl;

    std::cout << "brain value: " << brain << std::endl;
    std::cout << "brainptr value: " << *brainptr << std::endl;
    std::cout << "brainref value: " << brainref << std::endl;    
    
    return 0;
}