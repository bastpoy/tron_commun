#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{}

Base::~Base()
{}

Base::Base(const Base &copy)
{
    *this = copy;
}

Base &Base::operator=(const Base &copy)
{
    (void)copy;
    return (*this);
}

//FUNCTIONS

unsigned int getSeed() {
    return static_cast<unsigned int>(std::time(0)) ^ 
           (static_cast<unsigned int>(clock()) << 16);
}

Base *generate(void)
{
    std::srand(getSeed());
    int randomNumber = (std::rand() % 3) + 1;

    if(randomNumber == 1)
        return new A();
    else if(randomNumber == 2)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if(dynamic_cast<A*>(p) != NULL)
        std::cout << "le type de p est A" << std::endl;
    else if(dynamic_cast<B*>(p) != NULL)
        std::cout << "le type de p est B" << std::endl;
    else if(dynamic_cast<C*>(p) != NULL)
        std::cout << "le type de p est C" << std::endl;
    else
        std::cout << "unknow type" << std::endl;
}

void identify(Base& p)
{
    Base &test = p;
    try
    {
        test = dynamic_cast<A&>(p);
        std::cout << "le type de p est A" << std::endl;
    }
    catch(std::exception & e){}
    try
    {
        test = dynamic_cast<B&>(p);
        std::cout << "le type de p est B" << std::endl;
    }
    catch(std::exception & e){}
    try
    {
        test = dynamic_cast<C&>(p);
        std::cout << "le type de p est C" << std::endl;
    }
    catch(std::exception & e){}
}