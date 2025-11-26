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

    // --- Opérateurs de comparaison ---
    // Ils retournent tous un booléen (vrai/faux) et ne modifient pas l'objet (const).
    
    bool operator>(const Fixed& other) const;  // Est-ce que je suis strictement plus grand que 'other' ?
    bool operator<(const Fixed& other) const;  // Est-ce que je suis strictement plus petit que 'other' ?
    bool operator>=(const Fixed& other) const; // Est-ce que je suis plus grand ou égal à 'other' ?
    bool operator<=(const Fixed& other) const; // Est-ce que je suis plus petit ou égal à 'other' ?
    bool operator==(const Fixed& other) const; // Est-ce que je suis égal à 'other' ?

    bool operator!=(const Fixed& other) const; // Est-ce que je suis différent de 'other' ?

    // --- Opérateurs arithmétiques ---
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // --- Opérateurs d'incrémentation / décrémentation ---
    Fixed& operator++();    // Pré-incrémentation (++i)
    Fixed operator++(int);  // Post-incrémentation (i++)
    Fixed& operator--();    // Pré-décrémentation (--i)
    Fixed operator--(int);  // Post-décrémentation (i--)

    // --- Fonctions membres statiques (Min / Max) ---
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

private:
    int _rawValue;                     // stocke la valeur du nombre fixe sous forme d’entier
    static const int _fractionalBits;  // nombre de bits fractionnaires (même valeur pour toutes les instances)
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
