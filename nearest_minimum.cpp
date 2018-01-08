#include<iostream>
using namespace std;

/*
 * You are given an array of n integer numbers a0, a1, ..., an - 1. Find the distance between two closest (nearest)
 * minimums in it. It is guaranteed that in the array a minimum occurs at least two times.

Input
The first line contains positive integer n (2 ≤ n ≤ 10^5) — size of the given array.
 The second line contains n integers a0, a1, ..., an - 1 (1 ≤ ai ≤ 10^9) — elements of the array. It is guaranteed that
 in the array a minimum occurs at least two times.

Output
Print the only number — distance between two nearest minimums in the array.
 */
int main(){

    int n;

    cin >> n;

    int numbers[n];

    int minimum = -1;

    int lastOccurence;

    for(int i =0; i< n; i++){
        cin >> numbers[i];
        if(minimum > numbers[i] || minimum == -1){
            minimum = numbers[i];
            lastOccurence =i;
        }

    }

    int answer=-1;

    for(int i = lastOccurence+1; i< n; i++){
        if(numbers[i] == minimum){
            if(answer == -1 || answer > (i-lastOccurence)){
                answer = i - lastOccurence;
            }

            lastOccurence = i;
        }

    }

    cout << answer << endl;


    return 0;
}
