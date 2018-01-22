/*
 * You are given two positive integer numbers a and b. Permute (change order) of the digits of a to construct maximal number not exceeding b. No number in input and/or output can start with the digit 0.

It is allowed to leave a as it is.
Input

The first line contains integer a (1 ≤ a ≤ 1018). The second line contains integer b (1 ≤ b ≤ 1018). Numbers don't have leading zeroes. It is guaranteed that answer exists.
Output

Print the maximum possible number that is a permutation of digits of a and is not greater than b. The answer can't have any leading zeroes. It is guaranteed that the answer exists.

The number in the output should have exactly the same length as number a. It should be a permutation of digits of a.
 */

#include <iostream>
#include <queue>
#define integer long long

using namespace std;
integer a, b;

int getNumberDigitsB(){
    integer temp = b;
    int cont = 0;
    while(temp > 0){
        cont++;
        temp/=10;
    }
    return cont;
}


integer getMaximalWithLessDigits(priority_queue<int> d, int n){
    integer answer = 0;
    for(int i = 0; i < n && !d.empty(); i++){
        answer+=d.top();
        if(i!= n-1)answer*=10;
        d.pop();
    }

    return answer;

}

vector<int> getVectorB(){
    integer temp = b;

    vector<int> answer;

    while(temp > 0){
        answer.push_back(temp % 10);
        temp/=10;
    }

    vector<int> a;

    for(int i = answer.size()-1; i>=0; i--){
        a.push_back(answer[i]);
    }
    return a;
}

void printNumber(vector<int> d){
    integer ans =0;
    for(int i = 0; i < d.size(); i++){
        ans *=10;
        ans += d[i];
    }

    cout << ans << endl;
}

bool tryBuildMax(vector<int> a){


    vector<int> digitsB = getVectorB();

    vector<int> response;
    bool findLess = false;
    for(int i = 0; i < digitsB.size();){

        if(!findLess && a[digitsB[i]]> 0){
            a[digitsB[i]]--;
            response.push_back(digitsB[i]);
            i++;
        }else if(!findLess){

            while(true){

                for(int j = digitsB[i]-1; j>= 0; j--){

                    if(a[j]>0){

                        findLess = true;
                        response.push_back(j);
                        a[j]--;
                        break;

                    }

                }

                if(!findLess && response.size() > 0){
                    a[response[response.size()-1]]++;
                    response.erase(response.end()-1);
                    i--;
                }else{
                    break;
                }

            }


            if(!findLess) return false;
        }else{
            int d = 9;
            while(response.size() < digitsB.size()){
                while(a[d] == 0) d--;
                a[d]--;
                response.push_back(d);

            }

            printNumber(response);
            return true;
        }

    }

    printNumber(response);
    return true;

}

int main(){

    cin >> a >> b;

    vector<int> available(10, 0);

    priority_queue<int> digits;

    while(a > 0){
        int temp = a % 10;
        a/=10;
        digits.push(temp);
        available[temp]++;
    }

    int nDigitsb = getNumberDigitsB();

    if(nDigitsb > digits.size()){
        cout << getMaximalWithLessDigits(digits, digits.size()) << endl;
        return 0;
    }else if(tryBuildMax(available)){
        return 0;
    }else{
        cout << getMaximalWithLessDigits(digits, nDigitsb-1) << endl;
    }

    return 0;
}
