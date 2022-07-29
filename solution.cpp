#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <numeric>
#include "/Users/christophersebastian/Sudoku/Sudoku/solution.h"
#include "/Users/christophersebastian/Sudoku/Sudoku/cornersandbox.h"
#include "/Users/christophersebastian/Sudoku/Sudoku/guessing.h"
#include "/Users/christophersebastian/Sudoku/Sudoku/rowcolguess.h"



int counter = 0;
bool completed(std::vector<std::vector<int> > filler) {
    for (int k = 0; k < 9; k++) {
        for (int p =0; p < 9; p++) {
            if (filler[k][p] !=0) {
                counter++;
            } else {

            }
        }
    }
    if(counter == 81) {
        return true;
    } else {
        counter = 0;
        return false;
    }
}

const int rows = 9;
const int cols = 9;
void solution(std::vector<std::vector<int> >& array) {
    for (int rowcount = 0; rowcount < 9; rowcount++) {
        rowguess(array, rowcount);
        for (int colcount = 0; colcount < 9; colcount++) {
            if(array[rowcount][colcount] == 0) {
                for (int i = 0; i < 9; i++) {
                    if(array[rowcount][i] != 0 && std::find(temp.begin(), temp.end(), array[rowcount][i]) == temp.end()) {
                    temp.push_back(array[rowcount][i]);
                    }
                    if(array[i][colcount] != 0 && std::find(temp.begin(), temp.end(), array[i][colcount]) == temp.end()) {
                    temp.push_back(array[i][colcount]);
                }
            }
            
            if (temp.size() == 8) {
                int sum = std::accumulate(temp.begin(), temp.end(), 0);
                int final = 45 - sum;
                array[rowcount][colcount] = final;
                temp.clear();
            } else {
                possibleanswer(array, rowcount, colcount);
                if (possible.size() == 1) {
                    array[rowcount][colcount] = *possible.begin();
                } else {
                    guessing(array);
                }
                colguess(array, colcount);
                phistomefel(array);

                possible.clear();
                temp.clear();
                box.clear();
                boxwith0.clear();

            } 

        }
        
    }

}
}

/*
There are three conditions that I have to check

Eventually, switch the 0 in the loop to be a ticker that represents the row number that we are in
*/