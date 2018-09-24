#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * http://codeforces.com/problemset/problem/1051/C
 */


int main(){
    int n;
    int countA =0, countB =0;
    int prettyNumbers = 0;

    cin >> n;
    vector<int> count(101, 0);
    vector< queue<char> >qs(101);
    vector<int>input;


    int temp;
    for(int i =0; i < n; i++){
        cin >> temp;
        count[temp]++;
        input.push_back(temp);
    }

    for(int i =0; i < n; i++){
        if(count[input[i]] == 1){
            prettyNumbers++;
        }
    }


    for(int i =0; i< 101; i++){
        if(count[i] == 0) continue;

        if(count[i] > 2 && prettyNumbers%2 != 0){
            prettyNumbers++;
            if(countA < countB){
                countA++;
                qs[i].push('A');
                for(int j =0; j < count[i]-1; j++){
                    qs[i].push('B');
                }
            }else{
                qs[i].push('B');
                countB++;
                for(int j =0; j < count[i]-1; j++){
                    qs[i].push('A');
                }

            }
        }else{
            if(countA < countB){
                for(int j =0; j < count[i]; j++){
                    qs[i].push('A');
                }
                if(count[i] == 1)countA++;
            }else{
                for(int j =0; j < count[i]; j++){
                    qs[i].push('B');
                }
                if(count[i] == 1)countB++;
            }


        }


    }


    if(countA == countB){
        cout << "YES" << endl;

        for(int i =0; i< input.size(); i++){
            cout << qs[input[i]].front();
            qs[input[i]].pop();
        }
        cout << endl;
        return 0;
    }

    cout << "NO" << endl;

    return 0;
}
