#include "Array.hpp"

int main(void)
{
    try
    {
        Array<int> intarray = Array<int>();
        Array<float> floatarray = Array<float>();
        Array<double> doublearray(5);
        // Array<int> a(5);
        Array<int> b(6);

        // intarray.printElement(5);
        // floatarray.printElement(2);
        doublearray.printElement(4);
        intarray = b;
        intarray.printArray();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
    