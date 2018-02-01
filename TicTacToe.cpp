#include <iostream>
#include <vector>

using namespace std;

int s;
vector< vector<int> > board(3, vector<int>(3,0));
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

void copyArray(vector< vector<int> > &a, vector< vector<int> >b){
    a.push_back(vector<int>(3));
    a.push_back(vector<int>(3));
    a.push_back(vector<int>(3));

    for(int i = 0; i<3; i++){

        for(int j =0; j<3; j++){

            a[i][j] = b[i][j];
        }
    }


}

int getMove(vector< vector<int> > b, bool isMaximizer, int spacesLeft){

    if(spacesLeft ==0 ){
        return whoWins(b);
    }

    vector<int> weights;

    for(int i =0; i<3; i++){

        for(int j =0; j < 3; j++){

            if(b[i][j] == 0){
                vector< vector<int> > temp;
                copyArray(temp, b);
                if(isMaximizer) temp[i][j] =1;
                else temp[i][j] = -1;
                weights.push_back( getMove(temp, !isMaximizer, spacesLeft-1));
            }

        }
    }

    int temp = weights[0];
    if(isMaximizer){


        for(int i =1; i < weights.size(); i++)
            temp = max(temp, weights[i]);


    }else{
        for(int i =1; i < weights.size(); i++)
            temp = min(temp, weights[i]);
    }

    int index =-1;
    if(spacesLeft == s){

        for(int i =0; i<3; i++){

            for(int j =0; j<3; j++){
                if(b[i][j] == 0){
                    index++;
                    if(weights[index] == temp){
                        board[i][j] = 1;
                        return temp;
                    }
                }
            }
        }


    }

    return temp;
}



void printBoard(vector< vector<int> > b){

    cout << "    " <<1<<"  "<<2<<"  "<<3<<endl;
    for(int i = 0; i < 3; i++){

        cout << i+1<<" ";
        for(int j =0; j<3; j++){

            if(b[i][j] == 0){
                cout << "|  |";
            }else if(b[i][j] == 1){
                cout << "|X |";
            }else{
                 cout << "|O |";
            }

        }

        cout<<endl;
        cout << "  ------------"<<endl;
    }
}



int main(){



    s = 9;

    int row,col;

    bool isValid;

    int temp;
    while(s > 0){

        getMove(board, true, s);
        s--;

        temp = whoWins(board);

        if(temp == 1){
             cout << "GANA LA COMPUTADORA" << endl;
             return 0;
        }
        isValid = false;

        printBoard(board);
        cout << endl;

        cout << "-------------------------------" << endl << endl;
        if(s > 0){

            while(!isValid){
                cout <<"Ingresa la fila: ";
                cin >> row;
                cout <<"Ingresa la columna: ";
                cin >> col;

                row--; col--;

                if(board[row][col] == 0){
                    board[row][col] = -1;
                    s--;
                    isValid = true;
                }
            }

            printBoard(board);
            cout << endl;

            cout << "-------------------------------" << endl << endl;

            temp = whoWins(board);
                if(temp == -1){
                     cout << "GANASTE" << endl;
                 return 0;
                }
        }


    }


    temp = whoWins(board);

    if(temp ==0) cout << "EMPATE" << endl;
    else if(temp == 1) cout << "GANA LA COMPUTADORA" << endl;
    else cout << "GANASTE" << endl;


    return 0;
}
