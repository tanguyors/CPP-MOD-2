#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawValue(0) {
    std::cout << "default constructor called" << std::endl;
} 
//Ctr par default

Fixed::Fixed(int const value) 
{
    std::cout << "Int constructor called" << std::endl;
    _rawValue = value * 256; 
}  

Fixed::Fixed(float const value) 
{
    std::cout << "Float constructor called" << std::endl;
    _rawValue = roundf(value * 256);    
}

int Fixed::toInt(void) const 
{
    return _rawValue / 256;
}

 float Fixed::toFloat(void) const 
{
    return _rawValue / 256.0f;
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

Fixed::Fixed(const Fixed& copie) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copie;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{
    out << fixed.toFloat();
    return out;
}

/* 
operator<< : On dit au compilateur "Voici le mode d'emploi pour utiliser le symbole <<".
(std::ostream& out, ...)
 : Le premier paramètre est ce qu'il y a à gauche du << (ici std::cout, qu'on appelle out).
..., const Fixed& fixed) : Le deuxième paramètre est ce qu'il y a à droite du << (votre objet 
Fixed
).
*/