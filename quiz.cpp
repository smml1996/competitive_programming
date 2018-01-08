#include <iostream>

#define  modulus 1000000009
using namespace std;

/*
 * http://codeforces.com/problemset/problem/337/C
 *
 * Manao is taking part in a quiz. The quiz consists of n consecutive questions. A correct answer gives one point to the player. The game also has a counter of consecutive correct answers. When the player answers a question correctly, the number on this counter increases by 1. If the player answers a question incorrectly, the counter is reset, that is, the number on it reduces to 0. If after an answer the counter reaches the number k, then it is reset, and the player's score is doubled. Note that in this case, first 1 point is added to the player's score, and then the total score is doubled. At the beginning of the game, both the player's score and the counter of consecutive correct answers are set to zero.

Manao remembers that he has answered exactly m questions correctly. But he does not remember the order in which the questions came. He's trying to figure out what his minimum score may be. Help him and compute the remainder of the corresponding number after division by 1000000009 (109 + 9).

Input
The single line contains three space-separated integers n, m and k (2 ≤ k ≤ n ≤ 109; 0 ≤ m ≤ n).

Output
Print a single integer — the remainder from division of Manao's minimum possible score in the quiz by 1000000009 (109 + 9).
 */

long long nQuestions, bonus, correct;

long long getResto(long long D, long long d){

    long long q = D/d;

    long long resto = D%d;
    if(resto >=0) return resto;

    return D - (q-1)*d;
}

long long sumatoria(long long power){

    power ++;

    long long base =2;
    long long result= 1;

    while(power>0){

        if(power % 2 == 1){
            result*=base;
            result%=modulus;
        }

        base*=base;
        base%=modulus;
        power = power >> 1;


    }
    result-=2;
    result = getResto(result,modulus);

    result*=bonus;
    result%=modulus;
    return result;
}
int main(){

    cin >> nQuestions >> correct >> bonus;

    long long nBonuses = nQuestions/bonus;

    if(nQuestions-nBonuses >= correct){

        cout << correct << endl;
        return 0;
    }

    long long bonusesNeeded = correct - (nQuestions - nBonuses);

    long long score = correct - bonus*bonusesNeeded;

    score += sumatoria(bonusesNeeded);
    score %= modulus;

    cout << score << endl;
    return 0;
}
