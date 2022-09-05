#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <numeric>


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
int main() {
    std::vector<std::vector<int> > newarray = { {6,0,7,1,0,0,3,0,0}, 
                                                {0,0,0,0,3,0,0,0,2}, 
                                                {0,0,5,0,0,0,0,0,0},
                                                {0,2,0,8,0,0,0,0,0},
                                                {0,5,0,0,0,0,6,0,0}, 
                                                {0,0,0,0,0,7,0,0,4}, 
                                                {0,0,0,0,0,4,0,9,0}, 
                                                {0,8,0,0,0,8,0,0,0}, 
                                                {1,0,3,7,0,0,2,0,0} }; 


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

