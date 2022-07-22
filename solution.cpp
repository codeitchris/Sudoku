#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "solution.h"

bool isnot0(int x) {
        if (x != 0) {
            return true;
        } else {
            return false;
        }
    }

int solution(int value) {

    int rowcount = 0;
    int colcount = 0;

    const int rows = 8;
    const int cols = 8;
    int array[rows][cols];

    std::vector<int> temp;


    for (int i = 0; i!= 8; i++) {
        if(isnot0(array[0][i]) && std::binary_search(temp.begin(), temp.end(), array[0][i])) {
            temp.push_back(array[0][i]);
        }
        if(isnot0(array[i][0])&& std::binary_search(temp.begin(), temp.end(), array[i][0])) {
            temp.push_back(array[i][0]);
        }

    }



    if (temp.size() == 8) {
    int sum = std::accumulate(temp.begin(), temp.end(),
                                decltype(temp)::value_type(0));

    int final = 45 - sum;

    }


return 0;
}

/*
There are three conditions that I have to check

Eventually, switch the 0 in the loop to be a ticker that represents the row number that we are in
*/