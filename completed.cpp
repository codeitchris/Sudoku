#include <iostream>
#include <algorithm>
#include "solution.h"

bool completed(int filler[8][8]) {
    for (int k = 0; k !=8; k++) {
        for (int p =0; p!=8; p++) {
            if (isnot0(filler[k][p])) {

            } else {
                return false;

            }
        }
    }

return true;

}



