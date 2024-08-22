#include "Serializer.hpp"

int main(void)
{
    Data test = {36, "ouais"};
    uintptr_t ptr;

    ptr = Serializer::serialize(&test);
    test = *Serializer::deserialize(ptr);
    
    std::cout << test.number << std::endl;
    std::cout << test.string << std::endl;
}