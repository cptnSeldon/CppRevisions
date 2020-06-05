#include "bitarray.h"
#include "bitarraybyte.h"

int main()
{
    BitArray array(7);

    array += 2;
    array += 5;

    !array;

    array -= 3;

    cout << array;

    BitArrayByte byte;

    byte += 7;

    cout << byte;
}