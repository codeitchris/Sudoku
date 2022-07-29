#ifndef GUARD_solution_h
#define GUARD_solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <numeric>


void boxfun(std::vector<std::vector<int> > array, int shld, int work);
void possibleanswer(std::vector<std::vector<int> > array, int hope, int works);
void guessing(std::vector<std::vector<int> >& array);

extern std::vector<int> temp;
extern std::vector<int> temp;
extern std::list<int> possible;
extern std::vector<int> box;
extern std::vector<int> countsss;
extern std::vector<int> boxwith0;

#endif