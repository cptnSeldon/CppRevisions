#ifndef BITARRAY_H
#define BITARRAY_H

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class BitArray
{
    protected:  //évite l'utilisation de getters/setters dans les classes filles ainsi que les fonctions amies
        int * array;
        int size;

    public:
        //constructeur par paramètre/s
        BitArray(int size)
        {
            this->size = size;
            array = new int[size];

            cout << "size : " << size << endl;

            for(int i = 0; i < size; i++)
            {
                array[i] = 0;
            }
        }

        //destructeur
        ~BitArray()
        {
            clear();
        }

        //suppression des éléments du tableau
        void clear()
        {
            delete [] this->array;
            this->array = nullptr;
        }

        // https://en.cppreference.com/w/cpp/language/operators

        //surcharge : +=
        BitArray & operator+=(int index)
        {
            if(index > -1 && index < size) array[index] = 1;

            return *this;
        }

        //surcharge : -=
        BitArray & operator-=(int index)
        {
            if(index > -1 && index < size) array[index] = 0;

            return *this;
        }

        //surcharge : !
        void operator!()
        {
            for(int i = 0; i < size; i++)
            {
                if(array[i] == 0) array[i] = 1;
                else if(array[i] == 1) array[i] = 0;
            }
        }

        //surcharge : <<    -> fonction amie
        friend ostream& operator<<(ostream & os, BitArray & array);

};

ostream& operator<<(ostream & os, BitArray & outArray)
{
    //récupération des valeurs du tableau
    string result = "<_";
    result += to_string(outArray.array[outArray.size - 1]);

    for(int i = outArray.size - 2; i > 0 ; i--)
    {
        result += "_" + to_string(outArray.array[i]);
    }

    result += "_" + to_string(outArray.array[0]);
    result += "_>";

    return os << result << endl;
}


#endif //BITARRAY_H