#include "Fixed.hpp"

int main()
{
    Fixed a; //ctr default
    Fixed b(a); //ctr copie
    Fixed c; //ctr default
    c = b; 
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
}