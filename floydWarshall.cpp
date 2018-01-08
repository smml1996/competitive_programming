#include <iostream>
#include <vector>
#define infinity 100000000

using namespace std;

vector< vector<int> > matrix;
int n;

vector< vector<int> > floydWarshall(){

    vector< vector<int> > result =matrix;


    for (int i = 0; i <n ; ++i) {

        for (int j = 0; j < n; ++j) {
            for (int k = 0; k <n; ++k) {
                if(result[i][j]> result[i][k] + result[k][j]){
                    result[i][j] = result[i][k] + result[k][j];
                }
            }

        }
    }

    return result;
}


int main(){

    cin >> n;

    matrix = vector< vector<int> > (n, vector<int>(n, infinity));

    for(int i =0; i<n; i++)matrix[i][i] = 0;

    return 0;
}
