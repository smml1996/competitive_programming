#include <iostream>

using namespace std;

/*
 * http://codeforces.com/problemset/problem/1070/D
 */

long long todaysGarbage;
long long k; // units that a bag of garbage can carry
long long previousGarbage;
long long totalBagsNeeded; //answer
long long n; // days


int main(){


    cin >> n >> k;
    previousGarbage = 0;
    totalBagsNeeded = 0;


    long long temp;

    for(int i =0; i <n; i++){
        cin >> todaysGarbage;

        if(previousGarbage % k != 0){
            temp = ((previousGarbage/k)+1)*k - previousGarbage;
            if(temp > todaysGarbage){
                previousGarbage+=todaysGarbage;
                todaysGarbage = 0;
            }else{
                todaysGarbage-=temp;
                previousGarbage+=temp;
            }
            totalBagsNeeded+= (previousGarbage % k) == 0? previousGarbage / k : (previousGarbage/k)+1;
        }else{
            totalBagsNeeded+= previousGarbage/k;
        }

        previousGarbage = todaysGarbage % k;
        totalBagsNeeded+=todaysGarbage/k;
    }

    totalBagsNeeded+= (previousGarbage % k) == 0 ? previousGarbage/k: (previousGarbage/k) +1;

    cout <<  totalBagsNeeded << endl;



    return 0;
}
