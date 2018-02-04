#include <iostream>
#include <vector>
using namespace std;


#define mod 1000000007;

vector< vector<long long> > multiplicar( vector< vector<long long> > a , vector< vector<long long> > b){

    vector< vector<long long> > temp( 2, vector<long long>(2) );

    temp[0][0] = a[0][0]*b[0][0] + a[0][1]* b[1][0];
    temp[0][1] = a[0][0]*b[0][1]+ a[0][1]* b[1][1];
    temp[1][0] = a[1][0]*b[0][0]+ a[1][1]* b[1][0];
    temp[1][1] = a[1][0]*b[0][1]+ a[1][1]* b[1][1];


    return temp;
}

void sacarModulo(vector<vector<long long> > &m){

    for(int i =0; i<m.size(); i++){

        for(int j =0; j < m.size(); j++){
            m[i][j]%=mod;
        }
    }
}

long long fib(long long n){
    if(n == 0 ) return 0;
    if(n == 1) return 1;
    vector< vector<long long> > x(2, vector<long long>(2,1));

    x[1][1] = 0;

    vector< vector<long long> >result (2,vector<long long>(2,0));
    result[0][0] =1;
    result[1][1] =1;
    n--;


    while(n>0){

        if(n%2 != 0){
            result = multiplicar(result, x);
            sacarModulo(result);
        }

        x = multiplicar(x,x);

        sacarModulo(x);
        n/=2;

    }

    return result[0][0];



}
int main(){

    int t; cin >> t;

    long long temp;
    while(t--){

        cin >> temp;

        temp+=2;

        cout << fib(temp)<< endl;

    }





    return 0;
}
