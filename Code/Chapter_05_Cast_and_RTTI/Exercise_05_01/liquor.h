#ifndef LIQUOR_H
#define LIQUOR_H

#include "product.h"    //on doit juste inclure le header de product où on a déjà inclus la bibliothèque string et le namespace std

//Liquor est un Product plus spécialisé, il en hérite, ce qui veut dire qu'on peut utiliser ses attributs et fonctions
class Liquor : public Product
{
    public:
        //Constructeur par paramètres
        Liquor(const string name, float degree) : Product(name)
        {
            this->degree = degree;
        }

        //Autre méthode de notation :
        /*
            Liquor(const string name, float alcoholDegree) : Product(name), degree(alcoholDegree) {}
        */

        //Accesseur (getter)
        float getDegree() const
        {
            return degree;
        }

    private:
        //Variable de classe
        float degree;       //on peut le laisser en privé comme aucune autre classe ne l'utilise
};

#endif //LIQUOR_H