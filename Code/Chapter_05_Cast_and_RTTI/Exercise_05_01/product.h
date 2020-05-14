#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>       //sans cette bibliothèque, on ne peut pas utiliser string

using namespace std;    //std::string

class Product
{
    public:
        //Constructeur par paramètres
        Product(const string name)
        {
            this->name = name;
        }

        virtual ~Product() {}

        //Accesseur (getter)
        string getName()
        {
            return name;
        }


    protected:
        string name;    //si on veut que Liquor puisse y accéder, il faut que name soit mis en protected
};

#endif //PRODUCT_H