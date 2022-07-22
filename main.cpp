#include <iostream>
#include <algorithm>
#include <iterator>
#include "solution.h"
#include "completed.h"


int main() {
    
    int newarray = [[5,0,9,0,0,0,4,0,0], [7,0,8,3,0,4,9,0,0], [6,0,1,0,0,0,7,3,0],[4,6,2,5,0,0,0,0,0], [3,8,5,7,2,0,6,4,9], [1,0,7,4,0,8,2,0,0], [2,0,0,1,0,0,0,0,4], [0,0,3,0,4,0,0,8,7], [0,7,0,0,5,3,0,0,6]]

    while (completed(newarray) == flase) {
      solution(newarray);
    }

    for (int k = 0; k !=8; k++) {
      for (int p =0; p!=8; p++) {
        std::cout << newarray[k][p] << " "; 
        }
        std::cout << std::endl;

      }

    return 0;
}



/* 
Plan for the design of the file.

We need to input a Sudoku board. This board should be a matrix I think, it is the best 
way to represent this.

Computationally, we have to iterate through each cell. 

At each cell, we need to check whether or not we can put a number down. You do this by checking to see
if all other numbers 0-9 have been used in that row and in that column. If you can deduce a number
we will assign that cell the value that works.

If it doesn't, then we move to the next cell and check again.

So let's systemetize this

the first function that we sould write should be the one that determines what number goes in the cell
that we are currently in

The second function that we are going to write is going to the loop that sends you through each cell,
calling the first function that we wrote each time


*/