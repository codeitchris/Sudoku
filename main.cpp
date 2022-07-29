#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "/Users/christophersebastian/Sudoku/Sudoku/solution.h"
#include "/Users/christophersebastian/Sudoku/Sudoku/cornersandbox.h"
#include "/Users/christophersebastian/Sudoku/Sudoku/guessing.h"
#include "/Users/christophersebastian/Sudoku/Sudoku/rowcolguess.h"

int main() {
    std::vector<std::vector<int> > newarray = {{5,0,9,0,0,0,4,0,0}, 
                                                {7,0,8,3,0,4,9,0,0}, 
                                                {6,0,1,0,0,0,7,3,0},
                                                {4,6,2,5,0,0,0,0,0}, 
                                                {3,8,5,7,2,0,6,4,9}, 
                                                {1,0,7,4,0,8,2,0,0}, 
                                                {2,0,0,1,0,0,0,0,4}, 
                                                {0,0,3,0,4,0,0,8,7}, 
                                                {0,7,0,0,5,3,0,0,6}};


    while (completed(newarray) == false) {
      solution(newarray);
    }


    for (int k = 0; k !=9; k++) {
      for (int p =0; p!=9; p++) {
        std::cout << newarray[k][p] << " "; 
        }
        std::cout << std::endl;

      }

    return 0;
}


