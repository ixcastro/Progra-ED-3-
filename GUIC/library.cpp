#include "library.h"

library::library()
{

}

int library::str2int(string pData) {
    stringstream conv(pData);
    int temp = 0;
    conv >> temp;
    return temp;
}
