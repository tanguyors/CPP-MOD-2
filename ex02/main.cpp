#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}


/*
1. Les Créations (Initialisation)
Ligne 5 : Fixed a;
Appelle le Constructeur par Défaut.
a est créé avec _rawValue = 0.
Ligne 6 : Fixed const b( 10 );
Appelle le Constructeur Int (
Fixed(const int)
).
Il convertit 10 en virgule fixe : 10 * 256 = 2560.
b contient 2560.
Ligne 7 : Fixed const c( 42.42f );
Appelle le Constructeur Float (
Fixed(const float)
).
Il convertit 42.42 : roundf(42.42 * 256) = 10860.
c contient 10860.
Ligne 8 : Fixed const d( b );
Appelle le Constructeur de Copie (
Fixed(const Fixed&)
).
On crée d en copiant b.
d contient donc aussi 2560.
2. La Modification
Ligne 10 : a = Fixed( 1234.4321f );
Il se passe deux choses ici !
Fixed( 1234.4321f )
 : Crée un objet temporaire avec le constructeur Float.
a = ... : Appelle l'Opérateur d'Affectation (operator=).
Il copie la valeur de l'objet temporaire dans a.
Ensuite, l'objet temporaire est détruit (le destructeur est appelé pour lui).
3. L'Affichage (Le fameux operator<<)
Lignes 12-15 : std::cout << "a is " << a << std::endl; (etc.)
C'est ici que votre surcharge de l'opérateur << entre en jeu.
Pour a, b, c, d, il appelle votre fonction "Assistant Boulanger".
Cette fonction appelle 
toFloat()
 pour reconvertir les valeurs internes (10860 redevient 42.4218...) et les afficher.
4. La Conversion Explicite
Lignes 17-20 : std::cout << "a is " << a.toInt() << ...
Ici, on force l'appel à votre fonction 
toInt()
.
Elle prend la valeur interne et divise par 256 (division entière).
Exemple pour c : 10860 / 256 = 42. La partie décimale est coupée.
5. La Fin (Destruction)
Ligne 22 : return 0;
Le programme se termine.
Toutes les variables locales (a, b, c, d) sont détruites dans l'ordre inverse de leur création (d, puis c, puis b, puis a).
Le Destructeur est appelé pour chacune d'elles.
*/
