#include <iostream>

using namespace std;


/*
 * Two little greedy bears have found two pieces of cheese in the forest of weight a and b grams, correspondingly.
 * The bears are so greedy that they are ready to fight for the larger piece. That's where the fox comes in and starts
 * the dialog: "Little bears, wait a little, I want to make your pieces equal" "Come off it fox, how are you going to
 * do that?", the curious bears asked. "It's easy", said the fox. "If the mass of a certain piece is divisible by two,
 * then I can eat exactly a half of the piece. If the mass of a certain piece is divisible by three, then I can eat
 * exactly two-thirds, and if the mass is divisible by five, then I can eat four-fifths. I'll eat a little here and
 * there and make the pieces equal".

The little bears realize that the fox's proposal contains a catch. But at the same time they realize that they can not
 make the two pieces equal themselves. So they agreed to her proposal, but on one condition: the fox should make the
 pieces equal as quickly as possible. Find the minimum number of operations the fox needs to make pieces equal.

Input
The first line contains two space-separated integers a and b (1 ≤ a, b ≤ 109).

Output
If the fox is lying to the little bears and it is impossible to make the pieces equal, print -1. Otherwise, print the required minimum number of operations. If the pieces of the cheese are initially equal, the required number is 0.
 */

long a,  b;

long result =0;

long getPotencia(long potencia, long number, long &potenciacion){

    long result =0;
    potenciacion = 1;

    while(number % (potencia *potenciacion)==0){
        result++;
        potenciacion*=potencia;

    }

    return result;
}

void reduce(long number){
    long potenciacion;
    long pote2;

    long temp = getPotencia(number, a, potenciacion);

    long temp2 = getPotencia(number, b, pote2);



    result += temp > temp2 ? temp-temp2: temp2-temp;

    a/=potenciacion;
    b/=pote2;
}

int main(){




    cin >> a >> b;



    reduce(2);
    reduce(3);
    reduce(5);

    if(a != b ){
        cout<<-1<<endl;
        return 0;
    }

    cout << result <<endl;
    return 0;
}
