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


void rowguess(std::vector<std::vector<int> >& array, int rowval) {
    std::vector<int> positionalvals;
    std::vector<int> presentrowval;
    std::vector<std::vector<int> > nonpossiblevals;
    std::vector<int> required;
    std::vector<int> countervector;
    std::vector<int> answer;

    for(int r = 0; r < 9; r++) {
        if(array[rowval][r] == 0) {
            positionalvals.push_back(r);
        } else{
            presentrowval.push_back(array[rowval][r]);
        }
    }
    temp.clear();
    
    for(int k = 0; k < positionalvals.size(); k++) {
        for (int i = 0; i < 9; i++) {
            if(array[rowval][i] != 0 && std::find(temp.begin(), temp.end(), array[rowval][i]) == temp.end()) {
                temp.push_back(array[rowval][i]);
                }
            if(array[i][positionalvals[k]] != 0 && std::find(temp.begin(), temp.end(), array[i][positionalvals[k]]) == temp.end()) {
                temp.push_back(array[i][positionalvals[k]]);
            }

        }
        box.clear();
        boxfun(array, rowval, positionalvals[k]);
        for(int lol =0; lol < box.size(); lol++){
            if(std::find(temp.begin(), temp.end(), box[lol]) == temp.end()){
                temp.push_back(box[lol]);
            }
        }
        nonpossiblevals.push_back(temp);
        temp.clear();
        box.clear();
    }



    
    for(int iter = 1; iter < 10; iter++){
        if(std::find(presentrowval.begin(), presentrowval.end(), iter) == presentrowval.end()) {
            required.push_back(iter);
        }
    }

    for (int i =0; i < required.size(); i++){
        for (int j = 0; j < nonpossiblevals.size(); j++){
            if(std::find(nonpossiblevals[j].begin(), nonpossiblevals[j].end(), required[i]) == nonpossiblevals[j].end()){
                countervector.push_back(j);
                answer.push_back(required[i]);

            } 
            
        }

        if(countervector.size() == 1) {
            int onestep = countervector[0];
            int colfinal = positionalvals[onestep];
            array[rowval][colfinal] = answer[0];
            countervector.clear();
            answer.clear();
        }else{
            countervector.clear();
            answer.clear();
        }

        
    }

    nonpossiblevals.clear();
    required.clear();
    countervector.clear();
    answer.clear();
    temp.clear();
    presentrowval.clear();
    positionalvals.clear();
}

void colguess(std::vector<std::vector<int> >& array, int colval) {
    std::vector<int> positionalvals;
    std::vector<int> presentcolval;
    std::vector<std::vector<int> > nonpossiblevals;
    std::vector<int> required;
    std::vector<int> countervector;
    std::vector<int> answer;


    for(int r = 0; r < 9; r++) {
        if(array[r][colval] == 0) {
            positionalvals.push_back(r);
        } else{
            presentcolval.push_back(array[r][colval]);
        }
    }
    temp.clear();
    
    for(int k = 0; k < positionalvals.size(); k++) {
        for (int i = 0; i < 9; i++) {
            if(array[positionalvals[k]][i] != 0 && std::find(temp.begin(), temp.end(), array[positionalvals[k]][i]) == temp.end()) {
                temp.push_back(array[positionalvals[k]][i]);
                }
            if(array[i][colval] != 0 && std::find(temp.begin(), temp.end(), array[i][colval]) == temp.end()) {
                temp.push_back(array[i][colval]);
            }

        }
        box.clear();
        boxfun(array, positionalvals[k], colval);
        for(int lol =0; lol < box.size(); lol++){
            if(std::find(temp.begin(), temp.end(), box[lol]) == temp.end()){
                temp.push_back(box[lol]);
            }
        }
        nonpossiblevals.push_back(temp);
        temp.clear();
        box.clear();
    }
    
    for(int iter = 1; iter < 10; iter++){
        if(std::find(presentcolval.begin(), presentcolval.end(), iter) == presentcolval.end()) {
            required.push_back(iter);
        }
    }

    for (int i =0; i < required.size(); i++){
        for (int j = 0; j < nonpossiblevals.size(); j++){
            if(std::find(nonpossiblevals[j].begin(), nonpossiblevals[j].end(), required[i]) == nonpossiblevals[j].end()){
                countervector.push_back(j);
                answer.push_back(required[i]);

            } 
            
        }

        if(countervector.size() == 1) {
            int laststep = countervector[0];
            int rowfinal = positionalvals[laststep];
            array[rowfinal][colval] = answer[0];
            countervector.clear();
            answer.clear();
        }else{
            countervector.clear();
            answer.clear();
        }

        
    }

    nonpossiblevals.clear();
    required.clear();
    countervector.clear();
    answer.clear();
    temp.clear();
    presentcolval.clear();
    positionalvals.clear();
}