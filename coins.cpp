#include <iostream>

#include<vector>

using namespace std;

vector<int> weights;


vector<int> getObjetosEscogidos(vector< vector<int> > dp){

    vector<int> ans(dp.size(),0 );
    int j = dp[0].size()-1;
    int i = dp.size()-1;

    while(i >0 && j> -1){

        if(dp[i][j] == dp[i-1][j]) i-=1;
        else{
            ans[i]+=1;
            j -= weights[i];
        }
    }

    return ans;
}


int minimo(int a, int b){
    if(a > 0 && b > 0){
        if( a < b) return a;
        return b;
    }

    if(a == 0) return b;
    if(b == 0) return a;
}
int optimizar(int maxSize){

    vector< vector<int> > dp(weights.size(), vector<int>(maxSize+1));

    vector<int> objetosEscogidos(weights.size());

    for(int i = 0; i < weights.size(); i++){


        for(int j = 0; j<=maxSize; j++){

            if(i == 0 ){
                dp[i][j] = j;
            }else if(j == 0)

                dp[i][j] = 0;

            else if(j < weights[i])

                dp[i][j] = dp[i-1][j];

            else
                dp[i][j] = min(1 + dp[i][j - weights[i]], dp[i-1][j]);


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

    cout << "los objetos escogidos son: " << endl;
    for(int i = 0; i<objetosEscogidos.size(); i++){

        if(objetosEscogidos[i] > 0) cout << objetosEscogidos[i] << " de " << weights[i] << endl;

    }


    cout << endl;
    return dp[weights.size()-1][maxSize];


}

int main(){
    int n,m;

    cin >> n >> m;


    for(int i =0; i < n; i++){
        int temp;
        cin >> temp;
        weights.push_back(temp);
    }

    cout << "el numero minimo de monedas a utilizar es:  " << optimizar(m) << endl;

return 0;
}

