#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct s_data
{
    int number;
    std::string string;
} Data;

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data *deserialize(uintptr_t raw);
    
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &copy);
};

#endif