#include <iostream>

using namespace std;

/* http://codeforces.com/contest/937/problem/C
 * Julia is going to cook a chicken in the kitchen of her dormitory. To save energy, the stove in the kitchen automatically turns off after k minutes after turning on.

During cooking, Julia goes to the kitchen every d minutes and turns on the stove if it is turned off. While the cooker is turned off, it stays warm. The stove switches on and off instantly.

It is known that the chicken needs t minutes to be cooked on the stove, if it is turned on, and 2t minutes, if it is turned off. You need to find out, how much time will Julia have to cook the chicken, if it is considered that the chicken is cooked evenly, with constant speed when the stove is turned on and at a constant speed when it is turned off.

Input
The single line contains three integers k, d and t (1 ≤ k, d, t ≤ 1018).

Output
Print a single number, the total time of cooking in minutes. The relative or absolute error must not exceed 10 - 9.

Namely, let's assume that your answer is x and the answer of the jury is y. The checker program will consider your answer correct if .
 * */

int main(){

    double timeJulia, timeturnedOn, cookingTime;

    cin >> timeturnedOn >> timeJulia >> cookingTime;


    double temp = timeJulia;

    if(timeJulia < timeturnedOn){
        timeJulia = double((unsigned long long)(timeturnedOn/timeJulia) * timeJulia);
        if(timeJulia <  timeturnedOn) timeJulia+= temp;
    }

    double ganancia = timeturnedOn + (timeJulia - timeturnedOn) * 0.5;

    unsigned long long cycles = cookingTime / ganancia;


    double lastPart = cookingTime/ganancia - cycles;


    double firstFraction = timeturnedOn/timeJulia;

    double answer = timeJulia*cycles;
    if(lastPart > firstFraction){

        answer+=cookingTime - ganancia*cycles;
        double temp3 = cookingTime - timeturnedOn - cycles*ganancia;
        if(temp3 > 0)
            answer+=temp3;
    }else{

        answer+=cookingTime - ganancia*cycles;
    }

    printf("%.10f", answer);


    return 0;
}
