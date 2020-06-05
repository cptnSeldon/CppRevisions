#ifndef BITARRAYBYTE_H
#define BITARRAYBYTE_H

#include <math.h>
#include "bitarray.h"

class BitArrayByte : public BitArray //héritage
{
    public:
        BitArrayByte() : BitArray(8) { } //on sollicite le constructeur de BitArray

        friend ostream& operator<<(ostream & os, BitArrayByte & array); //pareil que pour la classe mère, on en fait une fonction amie
};

ostream& operator<<(ostream & os, BitArrayByte & outArray)
{
    //récupération des valeurs du tableau -> pareil que la surcharge de la classe mère
    string result = "<_";
    result += to_string(outArray.array[outArray.size - 1]);

    for(int i = outArray.size - 2; i > 0 ; i--)
    {
        result += "_" + to_string(outArray.array[i]);
    }

    result += "_" + to_string(outArray.array[0]);
    result += "_>";

    //conversion binaire -> décimale
    int decimal = 0;

    for(int i = 0; i < outArray.size; i++)
    {
        decimal += pow(2, i) * outArray.array[i];
    }

    return os << result << "\ndec : " << decimal << "\nhex : " << hex << decimal << dec << endl;
}

#endif //BITARRAYBYTE_H