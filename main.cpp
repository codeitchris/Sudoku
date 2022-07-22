#include <iostream>
#include <algorithm>
#include <iterator>
#include "solution.h"


int main() {
    
int a[] = {3, 6, 8, 33};
  int x = 8;
  bool exists = std::find(std::begin(a), std::end(a), x) != std::end(a);
    






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