/*
 * Petya loves lucky numbers. Everybody knows that positive integers are lucky if their decimal representation doesn't contain digits other than 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Lucky number is super lucky if it's decimal representation contains equal amount of digits 4 and 7. For example, numbers 47, 7744, 474477 are super lucky and 4, 744, 467 are not.

One day Petya came across a positive integer n. Help him to find the least super lucky number which is not less than n.
Input

The only line contains a positive integer n (1 ≤ n ≤ 109). This number doesn't have leading zeroes.
Output

Output the least super lucky number that is more than or equal to n.

Please, do not use the %lld specificator to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specificator.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> getVectorN(int n){

    vector<int> ans;

    while(n > 0){

        ans.push_back(n %10);
        n/=10;
    }

    return ans;
}

long long getAnswerWithNDigits(int numberDigits){
    long long answer=0;

    for(int i =0; i<numberDigits; i++){
        answer *=10;
        if(i < (numberDigits/2))answer +=4;
        else answer +=7;
    }

    return answer;
}

bool tryGetMinimal(vector<int> v, int n){


    long long answer =0;

    int fours = v.size()/2;
    int sevens = fours;
    bool greaterFound = false;

    for(int i =v.size()-1; i>=0; ){
        answer*=10;
        if((v[i]<=4 || greaterFound) && fours > 0){

            if(v[i] < 4) greaterFound = true;
            answer +=4;
            fours--;
            i--;
        }else if((v[i] <= 7 || greaterFound) && sevens > 0){
            if(v[i] < 7) greaterFound = true;
            answer +=7;
            sevens--;
            i--;
        }else if(answer> 0){

            answer /=10;
            while(answer >0 && answer %10==7){
                i++;
                answer/=10;
                sevens++;
            }

            if(answer %10 == 4 && sevens > 0){
                greaterFound = true;
            }else {
                return false;
            }

            answer/=10;
            answer*=10;
            answer+=7;
            sevens--;
            fours++;



        }else{
            return false;
        }
    }
    if(answer >= n){
        cout << answer << endl;
        return true;
    }
    return false;
}
int main(){

    int n;
    cin >> n;

    vector<int> vN = getVectorN(n);

    if(vN.size() % 2 != 0 ){
        cout << getAnswerWithNDigits(vN.size()+1) << endl;
    }else if(tryGetMinimal(vN, n)){
        return 0;
    }else{
        cout << getAnswerWithNDigits(vN.size()+2) << endl;
    }
    return 0;
}
