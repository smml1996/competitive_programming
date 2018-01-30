#include <iostream>

#include<vector>

using namespace std;


vector<int> values;
vector<int> weights;


vector<bool> getObjetosEscogidos(vector< vector<int> > dp){

    vector<bool> ans(dp.size()-1, false);
    int j = dp[0].size()-1;

    for(int i = dp.size()-1; i >=1; i--){

        if(dp[i][j] != dp[i-1][j]){
            ans[i-1] = true;
            j -= weights[i-1];
        }

    }

    return ans;
}


int optimizar(int maxSize){

    vector< vector<int> > dp(values.size()+1, vector<int>(maxSize+1));

    vector<bool> objetosEscogidos(values.size(), false);

    for(int i = 0; i <= values.size(); i++){


        for(int j = 0; j<=maxSize; j++){

            if(j == 0 || i == 0)

                dp[i][j] = 0;

            else if(j < weights[i-1])

                dp[i][j] = dp[i-1][j];

            else

                dp[i][j] = max(values[i-1] + dp[i-1][j - weights[i-1]], dp[i-1][j]);


        }

    }

    objetosEscogidos = getObjetosEscogidos(dp);


    for(int i = 0; i < dp.size(); i++){

        for(int j = 0; j < dp[0].size(); j++){
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;

    cout << "los objetos escogidos son (indexado desde 0): ";
    for(int i = 0; i<objetosEscogidos.size(); i++){

        if(objetosEscogidos[i]) cout << i << " ";

    }

    cout << endl;

    return dp[values.size()][maxSize];


}

int main(){
    int n,m;

    cin >> n >> m;

    for(int i =0; i < n; i++){
        int temp;
        cin >> temp;
        values.push_back(temp);
    }

    for(int i =0; i < n; i++){
        int temp;
        cin >> temp;
        weights.push_back(temp);
    }

    cout << "valor de la mochila optmizado: " << optimizar(m) << endl;

return 0;
}
