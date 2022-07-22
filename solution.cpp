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
const int rows = 8;
const int cols = 8;

int solution(int array[rows][cols]) {

    int rowcount = 0;
    int colcount = 0;

    std::vector<int> temp;

    for (rowcount; rowcount != 8; rowcount++) {
        for (colcount; colcount !=8; colcount++) {
            
            for (int i = 0; i!= 8; i++) {
                if(isnot0(array[rowcount][i]) && std::binary_search(temp.begin(), temp.end(), array[rowcount][i])) {
                    temp.push_back(array[rowcount][i]);
                }
                if(isnot0(array[i][colcount]) && std::binary_search(temp.begin(), temp.end(), array[i][colcount])) {
                    temp.push_back(array[i][colcount]);
                }

            }
                
                if (temp.size() == 8) {
                    int sum = std::accumulate(temp.begin(), temp.end(), decltype(temp)::value_type(0));

                     int final = 45 - sum;
                     array[rowcount][colcount] = final;
            }   else{
                temp.clear();
            }
        }
        
    }






return 0;


}

/*
There are three conditions that I have to check

Eventually, switch the 0 in the loop to be a ticker that represents the row number that we are in
*/