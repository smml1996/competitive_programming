#include <iostream>
#include <queue>

using namespace std;
/*
 * http://codeforces.com/contest/1038/problem/C
 */

long long sumA = 0, sumB = 0, sumListA = 0, sumListB = 0;


priority_queue<long long> listA, listB;
int main(){

    int n;

    cin >> n;

    long long temp;
    for(int i =0; i < n; i++){
        cin >> temp;
        sumListA +=temp;
        listA.push(temp);
    }
    for(int i =0; i < n; i++){
        cin >> temp;
        sumListB+= temp;
        listB.push(temp);
    }

    for(int i =0; i < 2*n; i++){
        if(!listA.empty() && !listB.empty()){

            if(listA.top() >= listB.top()){
                if(i%2 == 0){
                    sumA+= listA.top();

                }
                listA.pop();
            }else{
                if(i%2 !=0){
                    sumB+= listB.top();
                }
                listB.pop();
            }

        }else if(!listA.empty()){
            if(i%2 == 0){
                sumA+= listA.top();
            }
            listA.pop();
        }else{
            if(i%2!=0){
                sumB+=listB.top();
            }
            listB.pop();
        }

    }


    cout << sumA - sumB << endl;

    return 0;
}
