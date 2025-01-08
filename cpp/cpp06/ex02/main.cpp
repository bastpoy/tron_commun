#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base *base = generate();
    identify(base);
    identify(*base);
    std::cout << std::endl;

    Base *base1 = generate();
    identify(base1);
    identify(*base1);
    std::cout << std::endl;

    Base *base2 = generate();
    identify(base2);
    identify(*base2);
    std::cout << std::endl;
    
    Base *base3 = generate();
    identify(base3);
    identify(*base3);

    delete base;
    delete base1; 
    delete base2; 
    delete base3; 

}