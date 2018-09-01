#include <iostream>

using namespace std;

/* http://codeforces.com/problemset/problem/1028/A
 * A. Find Square
 */

int r, c;
int main(){

    cin >> r >> c;

    char temp;

    int posBr =-1, posBc, l=0;

    for(int i =0; i <r; i++){
        for(int j =0; j<c; j++){
            cin >> temp;

            if(temp == 'B'){
                if(posBr == -1){
                    posBr = i;
                    posBc =j;
                }
                l++;

                if(j + 1 == c){
                    int temp = l/2;

                    cout << (posBr + temp + 1) << " " << (posBc + temp +1) <<endl;
                    return 0;
                }
            }else if(posBr >-1 ){

                int temp = l/2;

                cout << (posBr + temp + 1) << " " << (posBc + temp +1) << endl;
                return 0;
            }

        }
    }


    return 0;
}
