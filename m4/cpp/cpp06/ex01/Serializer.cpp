#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::~Serializer()
{}

Serializer::Serializer(const Serializer &copy)
{
    *this = copy;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
    (void)copy;
    return (*this);
}

//STATIC FUNCTIONS

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t uintptr;

    uintptr = reinterpret_cast<uintptr_t>(ptr);
    return(uintptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *data;

    data = reinterpret_cast<Data*>(raw);
    return (data);
}