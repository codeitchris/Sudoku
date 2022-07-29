
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <numeric>
#include "solution.h"
#include "cornersandbox.h"
#include "guessing.h"
#include "rowcolguess.h"

    std::vector<int> temp;
    std::list<int> possible;
    std::vector<int> box;
    std::vector<int> countsss;
    std::vector<int> boxwith0;
void boxfun(std::vector<std::vector<int> > array, int shld, int work) {
    int x, y;
    x = shld;
    y = work;
    if (x < 3) {
        x = 0;
    } else if (2 < x &&  x < 6){
        x = 3;
    } else {
        x = 6;
    }

    if (y < 3) {
        y = 0;
    } else if (2 < y  && y < 6){
        y = 3;
    } else {
        y = 6;
    }
    int k = x + 3;
    int r = y + 3;

    for (int i = x; i < k; i++) {
        for (int j = y; j < r; j++) {
            if(array[i][j] != 0) {
                 box.push_back(array[i][j]);
            } else{
                boxwith0.push_back(i);
                boxwith0.push_back(j);    
            }
        }
    } 
}

void possibleanswer(std::vector<std::vector<int> > array, int hope, int works) {
    for (int car = 1; car < 10; car++) {
        if(std::find(temp.begin(), temp.end(), car) == temp.end()) {
            possible.push_back(car);
        } 
    }
    boxfun(array, hope, works);
    std::list<int>::iterator ptr = possible.begin();
        while (ptr != possible.end()) {
            if (std::find(box.begin(), box.end(), *ptr) != box.end()) {
                possible.erase(ptr++);
            } else {
                ptr++;
            }
        }
}

void guessing(std::vector<std::vector<int> >& array) {
    int numberofit = boxwith0.size()/2;
    int r = 0;
    int c = 1;
    temp.clear();
    std::vector<std::vector<int> > guesses;
    for(int k = 0; k < numberofit; k++) {
        for (int i = 0; i < 9; i++) {
            if(array[boxwith0[r]][i] != 0 && std::find(temp.begin(), temp.end(), array[boxwith0[r]][i]) == temp.end()) {
                temp.push_back(array[boxwith0[r]][i]);
                }
            if(array[i][boxwith0[c]] != 0 && std::find(temp.begin(), temp.end(), array[i][boxwith0[c]]) == temp.end()) {
                temp.push_back(array[i][boxwith0[c]]);
            }

        }
        guesses.push_back(temp);
        c = c + 2;
        r = r + 2;
        temp.clear();
    }

    std::vector<int> needed;
    for(int iter = 1; iter < 10; iter++){
        if(std::find(box.begin(), box.end(), iter) == box.end()) {
            needed.push_back(iter);
        }
    }
    std::vector<int> countervector;
    std::vector<int> answer;
    for (int i =0; i < needed.size(); i++){
        for (int j = 0; j < guesses.size(); j++){
            if(std::find(guesses[j].begin(), guesses[j].end(), needed[i]) == guesses[j].end()){
                countervector.push_back(j);
                answer.push_back(needed[i]);

            } 
            
        }

        if(countervector.size() == 1) {
            int really = countervector[0];
            int onelastime = really * 2;
            int finalrow = boxwith0[onelastime];
            int finalcol = boxwith0[onelastime + 1];
            array[finalrow][finalcol] = *(answer.begin());
            countervector.clear();
            answer.clear();
        }else{
            countervector.clear();
            answer.clear();
        }

        
    }

    guesses.clear();
    needed.clear();
    countervector.clear();
    answer.clear();

}