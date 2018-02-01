#include <iostream>
#include <vector>

using namespace std;



int whoWins(vector< vector<int> > b) {
    int sum = 0;
    int sum2 = 0;
    for (int i = 0; i < 3; i++) {

        sum2 += b[2 - i][2 - i];
        sum += b[i][i];
    }

    if (sum == 3 || sum == -3)return sum < 0 ? -1 : 1;
    if (sum2 == 3 || sum2 == -3)return sum2 < 0 ? -1 : 1;

    for (int i = 0; i < 3; i++) {
        sum = 0;
        sum2 = 0;
        for (int j = 0; j < 3; j++) {

            sum += b[i][j];
            sum2 += b[j][i];
        }

        if (sum == 3 || sum == -3)return sum < 0 ? -1 : 1;
        if (sum2 == 3 || sum2 == -3)return sum2 < 0 ? -1 : 1;
    }

    return 0;
}


int getMove(vector< vector<int> > b, bool isMaximizer, int spacesLeft){

    if(spacesLeft ==0 ){
        return whoWins(b);
    }

    vector<int> weights;
        
}



int main(){

    vector< vector<int> > board(3, vector<int>(3,0));


    return 0;
}
