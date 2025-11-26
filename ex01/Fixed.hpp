#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>


class Fixed {
public:
    Fixed(int const value);
    Fixed(float const value);
    Fixed();
    Fixed(const Fixed& copie);         // constructeur de copie : crée un objet à partir d’un autre
    Fixed& operator=(const Fixed& copie); // opérateur d’affectation : copie un Fixed existant dans un autre
    ~Fixed();                          // destructeur : appelé quand l’objet est détruit
    int getRawBits(void) const;        // renvoie la valeur brute (_rawValue) sans la modifier
    void setRawBits(int const raw);    // fixe la valeur brute (_rawValue) à partir d’un entier
    float toFloat(void) const;
    int toInt(void) const;

private:
    int _rawValue;                     // stocke la valeur du nombre fixe sous forme d’entier
    static const int _fractionalBits;  // nombre de bits fractionnaires (même valeur pour toutes les instances)
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
