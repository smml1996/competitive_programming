#include <iostream>
#include <vector>

using namespace std;

//http://codeforces.com/contest/1073/problem/A
char c, previousC;
int n ;

int main(){

    cin >> n >> previousC;

    for(int i =1; i < n; i++){
        cin >> c;
        if(c != previousC){
            cout << "YES" << endl;
            cout << previousC << c << endl;
            return 0;
        }
        previousC = c;
    }

    cout << "NO" << endl;



    return 0;
}
