#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
    private:
        std::string name;
        std::string title;

        Warlock();
        Warlock(const Warlock &copy);
        Warlock &operator=(const Warlock &copy);

    public:
        Warlock(std::string const name, std::string const title);
        ~Warlock();

        const std::string &getName(void) const;
        const std::string &getTitle(void) const;
        void setTitle(const std::string &title);
        void introduce() const;
};

#endif