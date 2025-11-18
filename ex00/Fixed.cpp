#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawValue(0) {
    std::cout << "default constructor called" << std::endl;
} 
//Ctr par default

Fixed::Fixed(const Fixed& copie)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copie;
}                                                         
// ctr de copie cet a dire copie un objet deja existant avec c attribut
Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        _rawValue = other._rawValue; // copie la valeur brute
    }
    return *this;                    // permet de chaîner les affectations
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return _rawValue;
}

void Fixed::setRawBits(int const raw) 
{
    _rawValue = raw;
}