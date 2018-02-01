#include<iostream>

#include<vector>

using namespace std;

int levenchstein(const string &s1,const string &s2){

    vector< vector<int> > dp(s1.size()+1,  vector<int>(s2.size()+1));
    
    for(int i =0; i < dp.size(); i++){
        for(int j =0; j < dp[0].size(); j++){
            if(j == 0) dp[i][j] = i;
            else if(i == 0) dp[i][j] = j;
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else dp[i][j] = 1 + min( min(dp[i][j-1], dp[i-1][j]),  dp[i-1][j-1] );
        }
    }

    for(int i =0; i < dp.size(); i++){

        for(int j =0; j < dp[0].size(); j++){

            cout << dp[i][j]  << " ";

        }

        cout << endl;
    }



    return dp[dp.size()-1][dp[0].size()-1];
}

int main(){

    string s1,s2;

    cin >> s1 >> s2;

    cout << levenchstein(s1, s2) << endl;

    return 0;
}




