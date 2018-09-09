#include <iostream>

using namespace std;

/*
 * http://codeforces.com/contest/1038/problem/B
 */


int main(){

    int n;
    cin >> n;
    if(n < 3){
        cout << "No" << endl;
        return 0;
    }

    int suma = n*(n+1)/2;;
    for(int i =2; i < n+1; ++i ){

        if( (suma-i) % i ==0 ){
            cout << "Yes" << endl;

            cout << 1 << " " << i << endl;

            cout << n-1 << " ";
            for(int k =1; k <= n; k++){
                if(k!= i){
                    cout << k << " ";
                }
            }
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
