#include <iostream>
#include <vector>

using namespace std;

/*
 * http://codeforces.com/problemset/problem/115/A
 */

int n;

vector<int> managers;

int getCount(const int &employee){
    if(managers[employee]  == employee){
        return 1;
    }

    return 1 + getCount(managers[employee]);
}

int main(){

    cin >> n;

    int temp;

    for(int i =0; i < n; i++){
        cin >> temp;
        managers.push_back(temp == -1 ? i:temp-1);
    }

    int maximo =0;

    for(int i =0; i < managers.size(); i++){
        maximo = max(getCount(i), maximo);
    }

    cout << maximo << endl;

    return 0;
}
