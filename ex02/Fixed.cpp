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

// --- Opérateurs de comparaison ---

bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

// --- Opérateurs arithmétiques ---

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// --- Opérateurs d'incrémentation / décrémentation ---

// Pré-incrémentation (++i) : On incrémente, PUIS on retourne l'objet modifié
Fixed& Fixed::operator++() {
    _rawValue++;
    return *this;
}

// Post-incrémentation (i++) : On crée une copie, on incrémente l'objet, PUIS on retourne la copie (ancienne valeur)
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _rawValue++;
    return temp;
}

// Pré-décrémentation (--i)
Fixed& Fixed::operator--() {
    _rawValue--;
    return *this;
}

// Post-décrémentation (i--)
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _rawValue--;
    return temp;
}

// --- Fonctions membres statiques (Min / Max) ---

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
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