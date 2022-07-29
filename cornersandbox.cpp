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


std::vector<std::vector<int> > notpossible;
void pencilmarkings(std::vector<std::vector<int> >& array, int rownum, int colnum) { 
    
    for (int i = 0; i < 9; i++) {
        if(array[rownum][i] != 0 && std::find(temp.begin(), temp.end(), array[rownum][i]) == temp.end()) {
                temp.push_back(array[rownum][i]);
        }
        if(array[i][colnum] != 0 && std::find(temp.begin(), temp.end(), array[i][colnum]) == temp.end()) {
                temp.push_back(array[i][colnum]);
        }
    }
        box.clear();
        boxfun(array, rownum, colnum);
        for(int lol =0; lol < box.size(); lol++){
            if(std::find(temp.begin(), temp.end(), box[lol]) == temp.end()){
                temp.push_back(box[lol]);
            }
        }
        notpossible.push_back(temp);
        temp.clear();
        box.clear();
}

void phistomefel(std::vector<std::vector<int> >& array){
    std::list<int> corners;
    std::vector<int> innerbox;
    std::vector<std::vector<int> > biginnerbox;
    std::vector<int> stillneeded;
    std::vector<int> boxneeded;
    std::vector< std::vector<int> > collectionbox;
    
    
    corners.push_back(array[0][0]);
    corners.push_back(array[0][1]);
    corners.push_back(array[1][0]);
    corners.push_back(array[1][1]);
    corners.push_back(array[0][7]);
    corners.push_back(array[0][8]);
    corners.push_back(array[1][7]);
    corners.push_back(array[1][8]);
    corners.push_back(array[7][0]);
    corners.push_back(array[7][1]);
    corners.push_back(array[8][0]);
    corners.push_back(array[8][1]);
    corners.push_back(array[7][7]);
    corners.push_back(array[7][8]);
    corners.push_back(array[8][7]);
    corners.push_back(array[8][8]);

    corners.remove(0);
    for(std::list<int>::iterator num = corners.begin(); num !=corners.end(); num++) {
        stillneeded.push_back(*num);
    }

    for(int i = 2; i < 7; i++){
        pencilmarkings(array, 2, i);
        if(array[2][i] != 0) {
            innerbox.push_back(array[2][i]);
        }
    }
    biginnerbox.push_back(innerbox);
    innerbox.clear();

    for(int i = 2; i < 7; i++){
        pencilmarkings(array, 6, i);
        if(array[6][i] != 0) {
            innerbox.push_back(array[6][i]);
        }
    }

    biginnerbox.push_back(innerbox);
    innerbox.clear();

    for(int i = 3; i < 6; i++){
        pencilmarkings(array, i, 2);
        if(array[i][2] != 0) {
            innerbox.push_back(array[i][2]);
        }
    }

    biginnerbox.push_back(innerbox);
    innerbox.clear();
    
    for(int i = 3; i < 6; i++){
        pencilmarkings(array, i, 6);
        if(array[i][6] != 0) {
            innerbox.push_back(array[i][6]);
        }
    }

    biginnerbox.push_back(innerbox);
    innerbox.clear();



    std::vector<int> countervector;
    std::vector<int> answer;
    for(int n =0; n<stillneeded.size(); n++) {
        for(int l =0; l<notpossible.size();l++){
            if(std::find(notpossible[l].begin(), notpossible[l].end(), stillneeded[n]) == notpossible[l].end()) {
                countervector.push_back(l);
                answer.push_back(stillneeded[n]);
            }
        }
        if(countervector.size() == 1) {
        int q = countervector[0];
        int rowfinal = 0;
        int colfainl = 0;
        if(q < 5) {
            rowfinal = 2;
        } else if(q < 10) {
            rowfinal =6;
        } else if(q == 10 || q == 13) {
            rowfinal = 3;
        } else if(q== 11 || q == 14) {
            rowfinal = 4;
        } else{
            rowfinal = 5;
        }  

        if(q == 0 || q == 5 || q == 10 || q == 11 || q == 12 ){
            colfainl = 2;
        } else if(q == 4 || q == 13 || q == 14 || q == 15|| q == 9){
            colfainl = 6;
        } else if( q ==1) {
            colfainl = 3;
        } else if( q ==2) {
            colfainl = 4;
        } else if( q ==3) {
            colfainl = 5;
        } else if( q ==6) {
            colfainl = 3;
        } else if( q ==7) {
            colfainl = 4;
        }else if( q ==8) {
            colfainl = 5;
        }


        array[rowfinal][colfainl] = answer[0];
        countervector.clear();
        answer.clear();
    }else{
        countervector.clear();
        answer.clear();
    }
    }


       
    stillneeded.clear();
    notpossible.clear();


}