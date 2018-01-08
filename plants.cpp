#include <iostream>

using namespace std;

/*
 * http://codeforces.com/problemset/problem/185/A
 */

long long getBase(long long years){
    long long result =1;

    long long temp = 2;
    while(years >0){

        if(years % 2 == 1 ){

            result *= temp;
            result %=1000000007;
        }

        temp *=temp;
        temp %= 1000000007;
        years = years >>1;

    }
    return result;
}

int main(){

    long long y ;
    cin >> y;


    long long result = getBase(y);
    result*=(result+1);

    result/=2;

    result%=1000000007;


    cout <<result<<endl;


    return 0;
}
