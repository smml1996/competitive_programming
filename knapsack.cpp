#include<iostream>

#include<vector>

using namespace std;

vector<int> v;

vector<int> w;


int optimize(int n, int backpackSize){


    vector< vector<int> > dp(n+1, vector<int>(backpackSize+1));

    for(int i =0; i <n+1; i++){

        for(int j =0; j<=backpackSize; j++){

            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(j < w[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max( v[i-1] + dp[i-1][j - w[i-1]], dp[i-1][j-1]);
        }
    }

    return dp[dp.size()-1][dp[0].size()-1];

}

int main(){
    int n, backpackSize;


    cin >> n >> backpackSize;

    int temp;
    for(int i =0; i< n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    for(int i =0; i< n; i++){
        cin >> temp;
        w.push_back(temp);
    }



    cout << optimize(n, backpackSize);



    return 0;
}
