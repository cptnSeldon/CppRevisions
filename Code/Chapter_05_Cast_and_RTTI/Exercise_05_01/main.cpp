#include <iostream>     //permet d'utiliser cout

#include "product.h"
#include "liquor.h"

int main()
{
    int elements = 10;

    //On crée une liste de produits de type Product qui contient 10 cases
    Product * products[elements];

    //on initialise les tableaux contenant les nom et degrés d'alcool qu'on utilisera pour créer des instances de Product et Liquor
    string productNames[] = { "Pain", "Lait", "Chocolat", "Cafe", "Salade" };

    string liquorNames[]  = { "Vodka", "Cervoise", "Vin rouge", "Amaretto", "Cognac" };
    float liquorDegrees[5]= { 40, 2.5, 12.5, 20, 44 };

    //On ajoute un nouveau produit basique à tous les index pairs du tableau products, et un nouveau product spécialisé tous les index impairs mais sous forme de Product
    // => comme Liquor hérite de Product, c'est faisable dans ce sens
    for (int i = 0; i < elements; i += 2)
    {
        products[i] = new Product(productNames[i/2]);
        products[i+1] = new Liquor(liquorNames[i/2], liquorDegrees[i/2]);

        //On a commencé par tester ce qui se passe si on essaie d'accéder aux membres de la classe Liquor sans utiliser de cast :
        //cout << products[i]->getName() << endl;
        //cout << products[i+1]->getName() << endl;
        //cout << products[i+1]->getDegree() << endl; => ne marche pas à ce stade ! Pour le compilateur, l'élément est de type Product et non Liquor
    }

    for(int i = 0; i < elements; i++)
    {
        //Là on va récupérer tous les éléments de type Liquor du tableau un à un
        Liquor * liquors = dynamic_cast<Liquor *>(products[i]);

        if(liquors != nullptr)  //évidemment, un élément de type purement Product n'est pas un élément Liquor (il manque l'attribut degree)
        {
            cout << liquors->getName() << "\n(" << liquors->getDegree() << ") " << endl;
        }
        else
        {
            cout << products[i]->getName() << endl;
        }

        cout << endl;
    }

    //Désallocation de la mémoire
    for(int i = 0; i < elements; i++)
    {
        delete products[i];
    }

    return 0;
}